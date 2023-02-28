#include"manager.h"

manager::manager(int id, string name, int position)
{
	this->id = id;
	this->name = name;
	this->pos = position;
}

void manager::showinfo()
{
	cout << "职工编号" << this->id
		<< "\t职工姓名" << this->name
		<< "\t岗位" << this->position() << endl;
}

string manager::position()
{
	return string("高级牛马");
}
