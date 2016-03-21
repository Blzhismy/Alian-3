#ifndef JLABLE_H_
#define JLABLE_H_

#include <string>
#include "JWindow.h"


namespace JFC
{

class JLable : public JWindow
{
public:
	JLable();
	JLable(SHORT x,SHORT y,SHORT width,SHORT height,
		const std::string& text,JWindow* parent);
	virtual ~JLable();

	virtual void Draw();

	void SetText(const std::string& text)
	{
		text_ = text;
	}

private:
	std::string text_;
};
}

#endif
