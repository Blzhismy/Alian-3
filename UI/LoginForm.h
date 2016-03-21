#ifndef _LOGIN_FORM_H_
#define _LOGIN_FORM_H_

#include <memory>
#include "../JFC/JForm.h"
#include "../JFC/JButton.h"

using namespace JFC;

namespace UI
{
	class LoginForm : public JForm
	{
	public:
		LoginForm(SHORT x, SHORT y, SHORT width, SHORT height, JWindow* parent = JWindow::Root_);
		~LoginForm();

		virtual void Draw();

		virtual void OnKeyEvent(JEvent* e);

	private:
		void DrawBorder();

		std::unique_ptr<JButton> btnLogin_;
		std::unique_ptr<JButton> btnExit_;
	};
}
#endif