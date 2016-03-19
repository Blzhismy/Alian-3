#ifndef _LOGIN_FORM_H_
#define _LOGIN_FORM_H_

#include "../JFC/JForm.h"

using namespace JFC;

namespace UI
{
	class LoginForm : public JForm
	{
	public:
		LoginForm(SHORT x, SHORT y, SHORT width, SHORT height, JWindow* parent = JWindow::Root_);
		~LoginForm();

		virtual void Draw();

	private:
		void DrawBorder();
	};
}
#endif