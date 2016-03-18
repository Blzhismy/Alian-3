#include "JFC\JApplication.h"
#include "JFC\JButton.h"

using namespace JFC;

int main()
{
	JApplication app;

	JButton btn(11, 2, 10,3, "test");
	btn.Show();

	JButton btn2(25, 2, 10, 3, "test2");
	btn2.Show();

	return app.Exec();  //ÏûÏ¢Ñ­»·
}