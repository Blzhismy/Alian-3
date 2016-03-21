#include "JFC\JApplication.h"
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

	LoginForm login(0, 0, 80, 25);
	login.Show();

	return app.Exec();  //ÏûÏ¢Ñ­»·
}