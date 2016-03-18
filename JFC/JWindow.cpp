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
	:JWindowBase(x,y,width,height),parent_(parent)
{
	if (Root_)
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
	if (!IsCurrent())
	{
		JWindow* LastCurrent = jApp->GetCurrent();
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
	jApp->SetCurrent(this);
}

bool JWindow::IsCurrent()
{
	return this == jApp->GetCurrent();
}
