#include "LoginForm.h"
#include "..\JFC\JEvent.h"

using namespace UI;
using namespace JFC;

LoginForm::LoginForm(SHORT x, SHORT y, SHORT width, SHORT height, JWindow* parent )
	:JForm(x,y,width,height,parent)
	,btnLogin_(std::make_unique<JButton>(22,17,11,3,"LOGIN",this))
	,btnExit_(std::make_unique<JButton>(48,17,10,3,"EXIT",this))
{
	AddChild(btnLogin_.get());
	AddChild(btnExit_.get());
}

LoginForm::~LoginForm()
{

}

void LoginForm::Draw()
{
	DrawBorder();

	SetTextColor(FCOLOR_BLUE);
	SetBkColor(BCOLOR_WHITE);

	DrawText(28, 3, "Login To The Bank System");
	DrawHLine(4, 25, 54, '-');

	DrawText(2, 23, "Bank System , Author: www.shengsheng.com");

	btnLogin_->Draw();
	btnExit_->Draw();
}

void LoginForm::DrawBorder()
{
	SetTextColor(FCOLOR_YELLO);
	SetBkColor(BCOLOR_RED);

	DrawHLine(0, 0, Width() - 1, '-');
	DrawHLine(Height()-1, 0, Width() - 1, '-');

	DrawVLine(0, 1, Height() - 2, ' ');
	DrawVLine(Width()-1, 1, Height() - 2, ' ');
}

 void LoginForm::OnKeyEvent(JEvent* e)
{
	JWindow* win = e->GetSender();
	int key = e->GetEventCode();
	if(win == btnLogin_.get() && key == KEY_ENTER)
	{
		// 进行事件处理
		e->Done();       //Enter事件处理完毕，不再进一步分发
	}

	if (win == btnExit_.get() && key == KEY_ENTER)
	{
		// 进行事件处理
		e->Done();       //Enter事件处理完毕，不再进一步分发
	}
	JForm::OnKeyEvent(e);
}