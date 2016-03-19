#include "JFC\JApplication.h"
#include "JFC\JWindow.h"
#include "JFC\JButton.h"

#include "UI/LoginForm.h"

using namespace JFC;
using namespace UI;

int main()
{
	JApplication app;

	/*
	JButton btn(11, 2, 10,3, "test");
	btn.Show();

	JButton btn2(25, 2, 10, 3, "test2");
	btn2.Show();
	*/

	//LoginForm login(0, 0, 80, 25);
	//login.Show();

	JWindow::Root_->DrawHLine(5, 5, 25, 'x');
	JWindow::Root_->Refresh();


	return app.Exec();  //ÏûÏ¢Ñ­»·
}