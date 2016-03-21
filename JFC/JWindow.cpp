#include <algorithm>
#include "JWindow.h"
#include "JEvent.h"
#include "JApplication.h"

using namespace JFC;

JWindow* JWindow::Root_;

JWindow::JWindow()
{
}

JWindow::JWindow(SHORT x,SHORT y,SHORT width,SHORT height,JWindow* parent)
	:JWindowBase(x,y,width,height),parent_(parent),canFocus_(false)
{
	if (!Root_)
		Root_ = this;

	if (parent_)
		parent_->AddChild(this);
}

JWindow::~JWindow()
{
	if (parent_)
	{
		parent_->DelChild(this);
	}
}

void JWindow::OnKeyEvent(JEvent* e)
{
	if (!e->IsDone())
	{
		if (parent_)
		{
			parent_->OnKeyEvent(e);
		}
	}
}

void JWindow::Draw()
{
	SetTextColor(FCOLOR_BLACK);
	SetBkColor(BCOLOR_WHITE);

	JRECT rect = { 0,0,Width() - 1, Height() - 1 };
	FillRect(rect);
}

void JWindow::Show()
{
	JWindow* LastCurrent;
	if (!IsCurrent())
	{
		LastCurrent = jApp->GetCurrent();
		SetCurrent();
		LastCurrent->Draw();
		LastCurrent->Refresh();
	}

	SetCurrent();
	Draw();
	Refresh();

}

void JWindow::AddChild(JWindow* win)
{
	childs_.push_back(win);
}

void JWindow::DelChild(JWindow* win)
{
	childs_.erase(std::remove(childs_.begin(), childs_.end(), win),childs_.end());
}


void JWindow::SetCurrent()
{
	std::vector<JWindow*>::const_iterator it;
	if (canFocus_)
		jApp->SetCurrent(this);
	else
	{
		// 遍历子窗口列表,查找是否有子窗口是当前窗口,如果有则break循环
		for (it = childs_.begin(); it != childs_.end(); ++it)
		{
			if ((*it)->canFocus_)
				break;
		}


		if (it != childs_.end())
		{
			JWindow* win = FindFirst(); // 查找第一个能够设置焦点的子窗口
			if (win)
			{
				jApp->SetCurrent(win);  // 将第一个能够设置焦点的子窗口设置为当前窗口
			}
			else
			{
				jApp->SetCurrent(this);
			}
		}

	}

}

bool JWindow::IsCurrent()
{
	return this == jApp->GetCurrent();
}

JWindow* JWindow::FindFirst()
{
	JWindow* p = NULL;
	std::vector<JWindow*>::const_iterator it;
	for (it = childs_.begin(); it != childs_.end(); ++it)
	{
		if ((*it)->canFocus_)
		{
			p = *it;
			break;
		}
	}

	return p;
}

JWindow* JWindow::FindLast()
{
	JWindow* p = NULL;
	std::vector<JWindow*>::const_reverse_iterator it;
	for (it = childs_.rbegin(); it != childs_.rend(); ++it)
	{
		if ((*it)->canFocus_)
		{
			p = *it;
			break;
		}
	}

	return p;
}

JWindow* JWindow::FindPrev(JWindow* win)
{
	JWindow* p = 0;

	std::vector<JWindow*>::const_reverse_iterator ri;
	ri = std::find(childs_.rbegin(), childs_.rend(), win);
	if (ri == childs_.rend())
		return  NULL;

	if (*ri == FindFirst())
		p = FindLast();
	else
	{
		++ri;
		for (; ri != childs_.rbegin(); ++ri)
		{
			if ((*ri)->canFocus_)
			{
				p = *ri;
				break;
			}
		}
	}

	return p;
}


JWindow* JWindow::FindNext(JWindow* win)
{
	JWindow* p = 0;

	std::vector<JWindow*>::const_iterator ri;
	ri = std::find(childs_.begin(), childs_.end(), win);
	if (ri == childs_.end())
		return  NULL;

	if (*ri == FindLast())
		p = FindFirst();
	else
	{
		++ri;
		for (; ri != childs_.end(); ++ri)
		{
			if ((*ri)->canFocus_)
			{
				p = *ri;
				break;
			}
		}
	}
	return p;
}
