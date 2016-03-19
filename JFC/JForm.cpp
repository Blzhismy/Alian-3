#include <vector>
#include <algorithm>
#include "JForm.h"

using namespace JFC;

JForm::JForm()
{
}

JForm::JForm(SHORT x, SHORT y, SHORT width, SHORT height,
	JWindow* parent)
{

}


JForm::~JForm()
{
}



void JForm::Draw()
{
	// 遍历子窗口列表，对各个子窗口进行绘制
	std::vector<JWindow*>::const_iterator it;
	for (it = childs_.begin(); it != childs_.end(); ++it)
	{
		(*it)->Draw();
	}
}