#include"manager.h"

manager::manager(int id, string name, int position)
{
	this->id = id;
	this->name = name;
	this->pos = position;
}

void manager::showinfo()
{
	cout << "ְ�����" << this->id
		<< "\tְ������" << this->name
		<< "\t��λ" << this->position() << endl;
}

string manager::position()
{
	return string("�߼�ţ��");
}
