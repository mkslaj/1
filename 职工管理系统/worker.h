#pragma once
#include<iostream>
using namespace std;

class worker {
public:
	//��ʾ������Ϣ
	virtual void showinfo() = 0;
	//��ʾ��λ����
	virtual string position() = 0;
	int id;
	string name;
	int pos;
};
