#include"boss.h"

boss::boss(int id, string name, int position)
{
	this->id = id;
	this->name = name;
	this->pos = position;
}

void boss::showinfo()
{
	cout << "ְ�����" << this->id
		<< "\tְ������" << this->name
		<< "\t��λ" << this->position() << endl;
}

string boss::position()
{
	return string("�ʱ���");
}
