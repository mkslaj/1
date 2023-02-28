#pragma once
#include<iostream>
using namespace std;

class worker {
public:
	//显示个人信息
	virtual void showinfo() = 0;
	//显示岗位名称
	virtual string position() = 0;
	int id;
	string name;
	int pos;
};
