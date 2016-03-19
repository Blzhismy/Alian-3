#include "LoginForm.h"

using namespace UI;

LoginForm::LoginForm(SHORT x, SHORT y, SHORT width, SHORT height, JWindow* parent )
	:JForm(x,y,width,height,parent)
{

}

LoginForm::~LoginForm()
{

}

void LoginForm::Draw()
{
	DrawBorder();
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