#include<iostream>
using namespace std;
#define max 1000

 
struct index {
	string name;
	int age;
	string adress;
	string phone;

};
struct add {
	struct index addx[max];
	int msize; 
};
void showmenu();
void showindex();
int isExist(add* abs, string str);
void fix(add* abs);