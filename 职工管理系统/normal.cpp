#include"normal.h"
//构造函数
normal::normal(int id, string name, int position ) {
	this->id = id;
	this->name = name;
	this->pos = position;
}
//显示信息
void normal::showinfo() {
	cout << "职工编号" << this->id
		<< "\t职工姓名" << this->name
		<< "\t岗位" << this->position() << endl;
}

//显示岗位
string normal::position()
{
	return string("牛马");
}
