#include"boss.h"

boss::boss(int id, string name, int position)
{
	this->id = id;
	this->name = name;
	this->pos = position;
}

void boss::showinfo()
{
	cout << "职工编号" << this->id
		<< "\t职工姓名" << this->name
		<< "\t岗位" << this->position() << endl;
}

string boss::position()
{
	return string("资本家");
}
