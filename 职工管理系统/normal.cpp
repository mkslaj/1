#include"normal.h"
//���캯��
normal::normal(int id, string name, int position ) {
	this->id = id;
	this->name = name;
	this->pos = position;
}
//��ʾ��Ϣ
void normal::showinfo() {
	cout << "ְ�����" << this->id
		<< "\tְ������" << this->name
		<< "\t��λ" << this->position() << endl;
}

//��ʾ��λ
string normal::position()
{
	return string("ţ��");
}
