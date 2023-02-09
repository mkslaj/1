#include "showmenu.h"
using namespace std;
#include<string>
void fix(add *abs) {
	string str;
	cout << "请输入要修改的联系人姓名" << endl;
		cin >> str;
	
	if (isExist(abs, str) != -1) {
		
		int select=0;
		int t = 1;
		while (t==1)
{
		cout << "\t1.修改姓名" << endl;
		cout << "\t2.修改年龄" << endl;
		cout << "\t3.修改电话" << endl;
		cout << "\t4.修改地址" << endl;
		cout << "\t5.显示修改后的信息" << endl;
			cin >> select;
		switch (select)
		{
		case 1:
			cout << "请输入修改的联系人姓名" << endl;
			cin >> abs->addx[isExist(abs, str)].name;
			break;
		case 2:
		cout << "请输入修改的联系人年龄" << endl;
		cin >> abs->addx[isExist(abs, str)].age;
		break;
		case 3:
			cout << "请输入修改的联系人电话号码" << endl;
		cin >> abs->addx[isExist(abs, str)].phone;
		break;
		case 4:
			cout << "请输入修改的联系人地址" << endl;
		cin >> abs->addx[isExist(abs, str)].adress;
		break;
		case 5 :cout << "\t姓名:\t" << abs->addx[isExist(abs, str)].name <<
			"\t年龄:\t" << abs->addx[isExist(abs, str)].age <<
			"\t电话:\t" << abs->addx[isExist(abs, str)].phone <<
			"\t地址:\t" << abs->addx[isExist(abs, str)].adress << endl;
			break;
		
		default:cout << "错误，请重新输入" << endl;
			break;
			
			
		}cout << "退出输入2，选择其他功能输入1" << endl;
			cin >> t;
			
		}	
		
		
	}
	else {
		cout << "查无此人" << endl;
		return;
	}
}


void addperson(add *abs) {
	if (abs->msize == max) {
		cout << "通讯录已满，无法添加" << endl;
		return ;
	}
	else
	{
		string  xname;
		string xphone;
		string xadress;
		int xage;
		cout << "请输入姓名" << endl;
		cin >>  xname;
		abs->addx[abs->msize].name =  xname;
		cout << "电话号码" << endl;
		cin >> xphone;
		abs->addx[abs->msize].phone = xphone;
		cout << "请输地址" << endl;
		cin >> xadress;
		abs->addx[abs->msize].adress = xadress;
		cout << "请输年龄" << endl;
		cin >> xage;
		abs->addx[abs->msize].age = xage;
		abs->msize++;
		cout << "添加完成" << endl;
		system("pause");
		system("cls");
		return;


	}
}
void showindex(add* abs) {
	int t;
	int i = 0;
	if (abs->addx[i].phone.size() != 0)
	{
	while (abs->addx[i].phone.size() != 0)
	{


	 cout<< "\t姓名:\t" <<     abs->addx[i].name  << 
			"\t年龄:\t" <<    abs->addx[i].age    <<
			"\t电话:\t" <<    abs->addx[i].phone  <<
		    "\t地址:\t" <<    abs->addx[i].adress << endl;
		i++;
		cout << "" << endl;

		}
	}
	else
	cout << "无人" << endl;
	cout << "输入1清空界面,输入2返回目录" << endl;
	cin >> t;
	system("pause");
	if (t==1)  system("cls"); 
	else
	return;
	
}

void deletex(add* abs) {
	string str;
	
	cout << "请输入要删除的联系人" <<  endl;
	cin >> str;
	if (isExist(abs, str) == -1) {
		cout << "查无此人" << endl;
	}
	else
	{
		abs->addx[isExist(abs, str)] = abs->addx[isExist(abs, str )+1];
		abs->msize--;
	
	}

}
void serch(add* abs) {
	cout << "请输入查找的联系人" << endl;
	string str;
	cin >> str;
	if (isExist(abs, str) != -1) {
		cout << "\t姓名:\t" << abs->addx[isExist(abs, str)].name <<
			"\t年龄:\t" << abs->addx[isExist(abs, str)].age <<
			"\t电话:\t" << abs->addx[isExist(abs, str)].phone <<
			"\t地址:\t" << abs->addx[isExist(abs, str)].adress << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "查无此人" << endl;
		return;
	}
	
}

int main() {
	
		  int select=0;
		  add abs;
		  abs.msize = 0;
		  string str;
		while (true)
		{
			showmenu();
		cin >> select;
		switch (select) {
		case 1: //加人
			addperson(&abs);
			break;
		case 2://显示
			showindex(&abs);
			break;
		case 3://删除
			deletex(&abs);
			break;
		case 4://查找
			serch(&abs);
			break;
		case 5://修改
			fix(&abs);
			break;
		case 6://清空
			break;
		case 0://退出
			cout << "再见" << endl;
			
			return 0;
			break;


		default:cout << "错误，请重新输入" << endl;
			break;
		}
	}
		system("pause");
	return 0;
	
}



int isExist(add*abs, string str) {
	for (int i = 0; i < abs->msize; i++) {
		if (abs->addx[i].name == str) {
			return i;

		}
	}return -1;
}
