#include "JButton.h"

using namespace JFC;

JButton::JButton()
{
}

JButton::JButton(SHORT x, SHORT y, SHORT width, SHORT height
	, const std::string text, JWindow* parent)
	:JWindow(x,y,width,height,parent),text_(text)
{
	SetCanFocus(true);
}

JButton::~JButton()
{
	SetCanFocus(true);
}

void JButton::Draw()
{
	if (IsCurrent())
	{
		SetTextColor(FCOLOR_WHITE);
		SetBkColor(BCOLOR_RED);
	}
	else
	{
		SetTextColor(FCOLOR_BLUE);
		SetBkColor(BCOLOR_GRAY);
	}

	JRECT rect = { 0,0,Width() - 1,Height() - 1 };
	FillRect(rect); // ���Ʊ���
	DrawText(text_);
}
