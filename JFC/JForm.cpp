#include <vector>
#include <algorithm>
#include "JForm.h"
#include "JEvent.h"
#include "JWindowBase.h"

using namespace JFC;

JForm::JForm()
{
}

JForm::JForm(SHORT x, SHORT y, SHORT width, SHORT height,
	JWindow* parent):JWindow(x,y,width,height,parent)
{

}


JForm::~JForm()
{
}


void JForm::Draw()
{
	// �����Ӵ����б��Ը����Ӵ��ڽ��л���
	std::vector<JWindow*>::const_iterator it;
	for (it = childs_.begin(); it != childs_.end(); ++it)
	{
		(*it)->Draw();
	}
}

void JForm::OnKeyEvent(JEvent * e)
{
	if (e->IsDone())
	{
		return;
	}

	if (e->GetSender() == this)
	{
		return;
	}

	int key = e->GetEventCode();
	JWindow* win;

	switch (key)
	{
		case KEY_UP:
		case KEY_LEFT:
			win = FindPrev(e->GetSender());
			if (win == NULL)
				return;

			win->Show();

			(e->GetSender())->Draw();
			(e->GetSender())->Refresh();
			break;

		case KEY_ENTER:
		case KEY_DOWN:
		case KEY_RIGHT:
		case KEY_TAB:
			win = FindNext(e->GetSender());
			if (win == NULL)
				return;

			win->Show();

			(e->GetSender())->Draw();
			(e->GetSender())->Refresh();
			break;

	}
}