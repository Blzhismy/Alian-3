#ifndef _JAPPICATION_H_
#define _JAPPICATION_H_

#include <memory>
#include "JWindow.h"

namespace JFC
{
	// JApplication ʹ��һ������ĵ���ģʽ��ģ����QT
class JApplication
{
public:
	JApplication();

	~JApplication();

	int Exec();         // ��Ϣѭ��
	JWindow* Root() const { return root_.get();  }
	JWindow* GetCurrent() const { return current_; }
	void SetCurrent(JWindow* window)
	{
		current_ = window;
	}

	void ShowCursor() const;
	void HideCursor() const;

	static JApplication* Instance() { return self_.get(); }

private:
	static std::unique_ptr<JApplication> self_;
	 std::unique_ptr<JWindow>(root_);         // ������
	 JWindow* current_;                       // ��ǰ���ܰ����¼��Ĵ���
	 //std::unique_ptr<JWindow>(root_);         // ������
	 //std::unique_ptr<JWindow>(current_);      // ��ǰ���ܰ����¼��Ĵ���
};

#define jApp JApplication::Instance()

}

#endif