#include "showmenu.h"
using namespace std;
#include<string>
void fix(add *abs) {
	string str;
	cout << "������Ҫ�޸ĵ���ϵ������" << endl;
		cin >> str;
	
	if (isExist(abs, str) != -1) {
		
		int select=0;
		int t = 1;
		while (t==1)
{
		cout << "\t1.�޸�����" << endl;
		cout << "\t2.�޸�����" << endl;
		cout << "\t3.�޸ĵ绰" << endl;
		cout << "\t4.�޸ĵ�ַ" << endl;
		cout << "\t5.��ʾ�޸ĺ����Ϣ" << endl;
			cin >> select;
		switch (select)
		{
		case 1:
			cout << "�������޸ĵ���ϵ������" << endl;
			cin >> abs->addx[isExist(abs, str)].name;
			break;
		case 2:
		cout << "�������޸ĵ���ϵ������" << endl;
		cin >> abs->addx[isExist(abs, str)].age;
		break;
		case 3:
			cout << "�������޸ĵ���ϵ�˵绰����" << endl;
		cin >> abs->addx[isExist(abs, str)].phone;
		break;
		case 4:
			cout << "�������޸ĵ���ϵ�˵�ַ" << endl;
		cin >> abs->addx[isExist(abs, str)].adress;
		break;
		case 5 :cout << "\t����:\t" << abs->addx[isExist(abs, str)].name <<
			"\t����:\t" << abs->addx[isExist(abs, str)].age <<
			"\t�绰:\t" << abs->addx[isExist(abs, str)].phone <<
			"\t��ַ:\t" << abs->addx[isExist(abs, str)].adress << endl;
			break;
		
		default:cout << "��������������" << endl;
			break;
			
			
		}cout << "�˳�����2��ѡ��������������1" << endl;
			cin >> t;
			
		}	
		
		
	}
	else {
		cout << "���޴���" << endl;
		return;
	}
}


void addperson(add *abs) {
	if (abs->msize == max) {
		cout << "ͨѶ¼�������޷����" << endl;
		return ;
	}
	else
	{
		string  xname;
		string xphone;
		string xadress;
		int xage;
		cout << "����������" << endl;
		cin >>  xname;
		abs->addx[abs->msize].name =  xname;
		cout << "�绰����" << endl;
		cin >> xphone;
		abs->addx[abs->msize].phone = xphone;
		cout << "�����ַ" << endl;
		cin >> xadress;
		abs->addx[abs->msize].adress = xadress;
		cout << "��������" << endl;
		cin >> xage;
		abs->addx[abs->msize].age = xage;
		abs->msize++;
		cout << "������" << endl;
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


	 cout<< "\t����:\t" <<     abs->addx[i].name  << 
			"\t����:\t" <<    abs->addx[i].age    <<
			"\t�绰:\t" <<    abs->addx[i].phone  <<
		    "\t��ַ:\t" <<    abs->addx[i].adress << endl;
		i++;
		cout << "" << endl;

		}
	}
	else
	cout << "����" << endl;
	cout << "����1��ս���,����2����Ŀ¼" << endl;
	cin >> t;
	system("pause");
	if (t==1)  system("cls"); 
	else
	return;
	
}

void deletex(add* abs) {
	string str;
	
	cout << "������Ҫɾ������ϵ��" <<  endl;
	cin >> str;
	if (isExist(abs, str) == -1) {
		cout << "���޴���" << endl;
	}
	else
	{
		abs->addx[isExist(abs, str)] = abs->addx[isExist(abs, str )+1];
		abs->msize--;
	
	}

}
void serch(add* abs) {
	cout << "��������ҵ���ϵ��" << endl;
	string str;
	cin >> str;
	if (isExist(abs, str) != -1) {
		cout << "\t����:\t" << abs->addx[isExist(abs, str)].name <<
			"\t����:\t" << abs->addx[isExist(abs, str)].age <<
			"\t�绰:\t" << abs->addx[isExist(abs, str)].phone <<
			"\t��ַ:\t" << abs->addx[isExist(abs, str)].adress << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "���޴���" << endl;
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
		case 1: //����
			addperson(&abs);
			break;
		case 2://��ʾ
			showindex(&abs);
			break;
		case 3://ɾ��
			deletex(&abs);
			break;
		case 4://����
			serch(&abs);
			break;
		case 5://�޸�
			fix(&abs);
			break;
		case 6://���
			break;
		case 0://�˳�
			cout << "�ټ�" << endl;
			
			return 0;
			break;


		default:cout << "��������������" << endl;
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
