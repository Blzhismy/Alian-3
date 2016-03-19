#ifndef JFORM_H_
#define JFORM_H_

#include "JWindow.h"

namespace JFC
{

class JForm : public JWindow
{
public:
	JForm();
	JForm(SHORT x, SHORT y, SHORT width, SHORT height,
		JWindow* parent);
	virtual ~JForm();

	virtual void Draw();
};

}

#endif
