#include <conio.h>
#include "JApplication.h"
#include "JEvent.h"

using namespace JFC;

std::unique_ptr<JApplication> JApplication::self_ = NULL;

JApplication::JApplication()
{
	if (self_.get())
		return;

	self_.reset(this);

	//֧������
	SetConsoleOutputCP(936);
	//���ÿ���̨��������С
	COORD size = { 80,25 };
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),size);
	
	HideCursor();
	root_ = std::make_unique<JWindow>(0,0,80,25,nullptr);
	current_ = root_.get();

	root_->Show();
}

JApplication::~JApplication()
{
	self_ = NULL;
}

int JApplication::Exec()
{
	while (1)
	{
		int key = _getch();
		if (key == 224)     // ���ⰴ���� �ϡ��¡����ҡ�F11��F12��home��Page Up��Page down��End��Delete��Insert 
		{
			key = 224 << 8 + _getch();
		}
		else if(key == 0)  // F1~F10
		{
			key = -1 * _getch();
		}
		if (current_)
		{
			JEvent e(key, current_);
			current_->OnKeyEvent(&e);
		}
	}

	return 0;
}

void JApplication::ShowCursor() const
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = true;
	SetConsoleCursorInfo(hOut, &cci);
}

void JApplication::HideCursor() const
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = false;
	SetConsoleCursorInfo(hOut, &cci);
}

