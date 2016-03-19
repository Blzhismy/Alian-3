#ifndef JWINDOW_BASE_H_
#define JWINDOW_BASE_H_

#include <windows.h>
#include <string>

using JRECT = SMALL_RECT;

//黑色
//蓝色
//绿色
//青色
//红色
//洋红
//棕色
//淡灰
//深灰
//淡蓝
//淡绿
//淡青
//淡红
//淡洋红
//黄色
//白色


#define FCOLOR_BLACK                0
#define FCOLOR_BLUE                 FOREGROUND_BLUE
#define FCOLOR_GREEN                FOREGROUND_GREEN
#define FCOLOR_CYAN                 FOREGROUND_BLUE | FOREGROUND_GREEN
#define FCOLOR_RED                  FOREGROUND_RED
#define FCOLOR_MAGENTA              FOREGROUND_RED | FOREGROUND_BLUE
#define FCOLOR_BLOWN                FOREGROUND_RED | FOREGROUND_GREEN
#define FCOLOR_GRAY                 FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
#define FCOLOR_DARKGRAY             FCOLOR_BLACK + BACKGROUND_INTENSITY
#define FCOLOR_LIGHTBLUE            FCOLOR_BLUE + BACKGROUND_INTENSITY
#define FCOLOR_LIGHTGREEN           FCOLOR_GREEN + FOREGREOUND_INTENSITY
#define FCOLOR_LIGHTCYAN            FCOLOR_CYAN + FOREGROUND_INTENSITY
#define FCOLOR_LIGHTRED             FCOLOR_RED + FOREGROUND_INTENSITY
#define FCOLOR_LIGHTMAGENTA         FCOLOR_MAGENTA + FOREGROUND_INTENSITY
#define FCOLOR_YELLO                FCOLOR_BLOWN + FOREGROUND_INTENSITY
#define FCOLOR_WHITE                FCOLOR_GRAY + FOREGROUND_INTENSITY

#define BCOLOR_BLACK                0
#define BCOLOR_BLUE                 BACKGROUND_BLUE
#define BCOLOR_GREEN                BACKGROUND_GREEN
#define BCOLOR_CYAN                 BACKGROUND_BLUE | BACKGROUND_GREEN
#define BCOLOR_RED                  BACKGROUND_RED
#define BCOLOR_MAGENTA              BACKGROUND_RED | BACKGROUND_BLUE
#define BCOLOR_BLOWN                BACKGROUND_RED | BACKGROUND_GREEN
#define BCOLOR_GRAY                 BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE
#define BCOLOR_DARKGRAY             BCOLOR_BLACK + BACKGROUND_INTENSITY
#define BCOLOR_LIGHTBLUE            BCOLOR_BLUE + BACKGROUND_INTENSITY
#define BCOLOR_LIGHTGREEN           BCOLOR_GREEN + BACKGROUND_INTENSITY
#define BCOLOR_LIGHTCYAN            BCOLOR_CYAN + BACKGROUND_INTENSITY
#define BCOLOR_LIGHTRED             BCOLOR_RED + BACKGROUND_INTENSITY
#define BCOLOR_LIGHTMAGENTA         BCOLOR_MAGENTA + BACKGROUND_INTENSITY
#define BCOLOR_YELLO                BCOLOR_BLOWN + BACKGROUND_INTENSITY
#define BCOLOR_WHITE                BCOLOR_GRAY + BACKGROUND_INTENSITY

namespace JFC
{

class JWindowBase
{
public:
	JWindowBase();
	JWindowBase(SHORT x, SHORT y, SHORT width, SHORT height);
	virtual ~JWindowBase();

	// 设置前景色
	void SetTextColor(WORD fColor) { fColor_ = fColor; }
	// 获取前景色
	WORD GetTextColor() const { return fColor_;  }

	// 设置背景色
	void SetBkColor(WORD bColor) { bColor_ = bColor;}
	// 获取背景色
	WORD GetBkColor() const { return bColor_;  }

	SHORT Width() const { return width_;  }
	SHORT Height() const { return height_; }

	// 刷新窗口
	void Refresh();

	// 设置光标位置
	void SetCursorPos(SHORT x, SHORT y);

	// 清除矩形区域
	void FillRect(JRECT rect);

	// 绘制文本（x,y相对于本窗口的位置，并不是相对整个控制台窗口的位置)
	void DrawText(SHORT x, SHORT y, const std::string& text);

	// 在窗口正中间绘制文本
	void DrawText(const std::string& text);

	// 在水平位置画线
	void DrawHLine(SHORT y, SHORT x1, SHORT x2, char ch);

	// 在垂直位置画线
	void DrawVLine(SHORT x, SHORT y1, SHORT y2, char ch);

	// 清除窗口
	void ClearWindow();
	

private:
	class ScreenBuffer
	{
	public:
		ScreenBuffer()
		{

		}

		~ScreenBuffer()
		{

		}

	public:
		void write(SHORT x, SHORT y, CHAR_INFO ci)
		{
			buffer_[y * 80 + x] = ci;
		}

		void write(SHORT x, SHORT y, const std::string& str, WORD fColor,WORD bColor)
		{
			/*typedef struct _CHAR_INFO
			{
				union {
					WCHAR UnicodeChar;
					CHAR AsciiChar;
				}Char;
				WORD Attributes;
			}CHAR_INFO, *PCHAR_INFO;
			*/
			CHAR_INFO ci;
			ci.Attributes = fColor | bColor;

			for (size_t i = 0; i < str.length(); ++i)
			{
				ci.Char.AsciiChar = str[i];
				write(x + i, y, ci);
			}
		}

		void refresh(SHORT x, SHORT y, SHORT width, SHORT height)
		{
			/*BOOL WINAPI WriteConsoleOutput(
				_In_          HANDLE      hConsoleOutput,
				_In_    const CHAR_INFO   *lpBuffer,
				_In_          COORD       dwBufferSize,
				_In_          COORD       dwBufferCoord,
				_Inout_       PSMALL_RECT lpWriteRegion
				);
				*/
			COORD size = { 80,25 };
			COORD coord = { x,y };
			JRECT rect = { x,y,x + width-1,y + height-1 };

			WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE),
				buffer_,
				size,
				coord,
				&rect//写入成功后会返回实际写入的区域
				);
		}

		CHAR_INFO buffer_[80 * 25];
	};

public:
	static ScreenBuffer sb_;

protected:
	WORD fColor_;    //前景色（文本颜色）
	WORD bColor_;    //背景色
	SHORT x_;        //x坐标
	SHORT y_;        //y坐标
	SHORT width_;    //宽度
	SHORT height_;   //高度
};

}


#endif
