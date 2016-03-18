#ifndef _JAPPICATION_H_
#define _JAPPICATION_H_

#include <memory>
#include "JWindow.h"

namespace JFC
{
	// JApplication 使用一种特殊的单例模式，模仿自QT
class JApplication
{
public:
	JApplication();

	~JApplication();

	int Exec();         // 消息循环
	JWindow* Root() const { return root_.get();  }
	JWindow* GetCurrent() const { return current_; }
	void SetCurrent(JWindow* window)
	{
		current_ = window;
	}

	void ShowCursor() const;
	void HideCursor() const;

	static JApplication* Instance() { return self_.get(); }

private:
	static std::unique_ptr<JApplication> self_;
	 std::unique_ptr<JWindow>(root_);         // 根窗口
	 JWindow* current_;                       // 当前接受按键事件的窗口
	 //std::unique_ptr<JWindow>(root_);         // 根窗口
	 //std::unique_ptr<JWindow>(current_);      // 当前接受按键事件的窗口
};

#define jApp JApplication::Instance()

}

#endif