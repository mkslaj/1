#pragma once
#include"iostream"
using namespace std;
#include"worker.h"
class normal :public worker {
public:
	normal(int id, string name, int position);
	virtual void showinfo();
	virtual string position();
};