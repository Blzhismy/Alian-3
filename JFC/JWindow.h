#ifndef JWINDOW_H_
#define JWINDOW_H_

#include <vector>
#include "JWindowBase.h"

namespace JFC
{

	class JEvent;

class JWindow : public JWindowBase
{
public:
	JWindow();
	JWindow(SHORT x, SHORT y, SHORT width, SHORT height, JWindow* parent=Root_);
	virtual ~JWindow();

	virtual void OnKeyEvent(JEvent* e);
	virtual void Draw();
	void Show();

	void AddChild(JWindow* win);
	void DelChild(JWindow* win);

	void SetCurrent();
	bool IsCurrent();


public:
	static JWindow* Root_;

protected:
	JWindow* parent_;
	std::vector<JWindow*> childs_;
};
}
#endif
