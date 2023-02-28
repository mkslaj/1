#pragma once
#include<iostream>
using namespace std;
#include"normal.h"
#include"boss.h"
#include"manager.h"
#include<fstream>
#define flname "file.txt"
class workermanager {
public:
	workermanager();
	void showmenu();
	void exitmenu();
	void addmessage();
	void showmessage();
	void delmen();
	int IsExist(int id);
	void changemen();
	void serchmen();
	void save();
	void QuickSort();
	void clean();
	int getnum();
	int mnum;
	worker** mArray;
	bool fileIsEmpty;
	~workermanager();
};
