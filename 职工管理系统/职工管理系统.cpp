#include"workermanager.h"
#include"normal.h"
#include"boss.h"
#include"manager.h"

int main() {
	workermanager wm;
	int choose =  0;
	while (true)
	{
		wm.showmenu();
		cout << "������" << endl;
		cin >> choose; 
		while  (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "����������:" << endl;
			cin >> choose;
		}
	switch (choose)
		{
		case 0://�˳�����ϵͳ
			wm.exitmenu();
			break;
		case 1://����ְ����Ϣ
			wm.addmessage();
			break;
		case 2://��ʾְ����Ϣ����ȡ�ļ���bug��
			wm.showmessage();
			break;
		case 3://ɾ����ְְ��
			wm.delmen();
			break;
		case 4://�޸�ְ����Ϣ����ȡ�ļ���bug��
			wm.changemen();
			break;
		case 5://����ְ����Ϣ����ȡ�ļ���bug��
			wm.serchmen();
			break;
		case 6://���ձ������(�ݹ鴫����bug)
			wm.QuickSort();
			break;
		case 7://��������ĵ�
			wm.clean();
			break;


		default:
			system("cls");
			break;
			
		}
	
	}
	system("pause");
	return 0;
}