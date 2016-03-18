#ifndef JBUTTON_H_
#define JBUTTON_H_

#include <string>
#include "JWindow.h"

namespace JFC
{

class JButton:public JWindow
{
public:
	JButton(void);
	JButton(SHORT x, SHORT y, SHORT width, SHORT height
		, const std::string text = std::string(), JWindow* parent = Root_);
	virtual ~JButton();

	virtual void Draw();
protected:
	std::string text_;
};
}
#endif
