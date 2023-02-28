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
		cout << "请输入" << endl;
		cin >> choose; 
		while  (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "请输入数字:" << endl;
			cin >> choose;
		}
	switch (choose)
		{
		case 0://退出管理系统
			wm.exitmenu();
			break;
		case 1://增加职工信息
			wm.addmessage();
			break;
		case 2://显示职工信息（读取文件有bug）
			wm.showmessage();
			break;
		case 3://删除离职职工
			wm.delmen();
			break;
		case 4://修改职工信息（读取文件有bug）
			wm.changemen();
			break;
		case 5://查找职工信息（读取文件有bug）
			wm.serchmen();
			break;
		case 6://按照编号排序(递归传入有bug)
			wm.QuickSort();
			break;
		case 7://清空所有文档
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