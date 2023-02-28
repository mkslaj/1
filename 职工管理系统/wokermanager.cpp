#include"workermanager.h"

workermanager::workermanager() {
	//文件不存在
	ifstream ifs;
	ifs.open(flname, ios::in);//读文件
		if (!ifs.is_open()) {
			cout << "文件不存在" << endl;
			//初始化
		this->mArray = NULL;
		this->mnum = 0;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
		//文件存在但是无记录
		char ch;
		ifs >> ch;
		if (ifs.eof()) {
			cout << "文件夹为空" << endl;
			this->fileIsEmpty = true;
			this->mArray = NULL;
			this->mnum = 0;
			ifs.close();
			return;

		}
		int num = this->getnum();
		this->mnum = num;
}
//统计文件内人数
int workermanager::getnum() {
	ifstream ifs;
	ifs.open(flname, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>>did)
	{
		num++;
	}
	ifs.close();
	return num;
  }
workermanager::~workermanager() {
	if (this->mArray != NULL) {
		delete[] this->mArray;
		this->mArray = NULL;
	}
}	

void workermanager::save() {
	ofstream ofs;
	ofs.open(flname , ios::out | ios::binary);
	for (int i = 0; i < this->mnum; i++) {
		ofs<< this->mArray[i]->id << " "
			<< this->mArray[i]->name << " "
			<<this->mArray[i]->pos << endl;
	}
	ofs.close();
}

void workermanager::QuickSort() {
	if (this->fileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	
	int i = 0;
	int j = mnum;
	if (this->mArray[i]->id >= this->mArray[j]->id) {
		return;
	}
	int temp =this->mArray[i]->id;
	while (i != j) {
		while (this->mArray[j]->id>= temp && i < j) {
			j--;
		}
		while (this->mArray[i]->id <= temp && i < j) {
			i++;
		}
		if (i < j) {
			swap(this->mArray[i], this->mArray[j]);
		}
	}
	
	cout << "排序成功" << endl;
	this->save();

	//将基准temp放于自己的位置，（第i个位置）
	
	
}

void workermanager::clean()
{
	cout << "是否清空" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;
	int sel = 0;
	cin >> sel;
	if (sel==1) {
		//打开 ios：：trunc如果存在删除文件重新创建
		ofstream ofs(flname, ios::trunc);
		ofs.close();
	}
	if (this->mArray != NULL) {
		for (int i = 0; i < this->mnum;i++) {
			if (this->mArray[i] != NULL) {
				delete this->mArray[i];
			}
		}
		this->mnum = 0;
	delete[] this->mArray;
	this->mArray = NULL;
	this->fileIsEmpty = true;
	cout << "已清空" << endl;
	}system("pause");
	system("cls");
	
}


  

	void workermanager::showmenu(){
		cout << "********************************************" << endl;
		cout << "*********  欢迎使用职工管理系统！ **********" << endl;
		cout << "*************  0.退出管理程序  *************" << endl;
		cout << "*************  1.增加职工信息  *************" << endl;
		cout << "*************  2.显示职工信息  *************" << endl;
		cout << "*************  3.删除离职职工  *************" << endl;
		cout << "*************  4.修改职工信息  *************" << endl;
		cout << "*************  5.查找职工信息  *************" << endl;
		cout << "*************  6.按照编号排序  *************" << endl;
		cout << "*************  7.清空所有文档  *************" << endl;
		cout << "********************************************" << endl;
		cout << endl;
} 
	void workermanager::exitmenu() {
		cout << "按任意键退出" << endl;
		system("pause");
		exit(0);
	}
	
	void workermanager::showmessage()
	{
		
			if (this->fileIsEmpty) {
				cout << "文件空" << endl;
			}
			else {
				for (int i = 0; i <mnum; i++)
				{
					this->mArray[i]->showinfo();
				}
			
				}
			cout << "按任意键清屏" << endl;
			system("pause");
			system("cls");
	}		

		
	
	int workermanager::IsExist(int id) {
	   //查无此人
		int index = -1;
		cout << "查无此人" << endl;
		for (int i = 0; i < this->mnum; i++) {
			if (id == this->mArray[i]->id) {
				index = i;
			}
		}return index;
	}
	void workermanager::changemen()
	{
		//找到需要修改的员工
		int id = 0;
		cout << "请输入需要修改员工编号" << endl;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1) {
			delete this->mArray[index];
			int id = 0;
			string name;
			int pos = 0;
			cout << "请输入员工新编号" << endl;
			cin >> id;
			cout << "请输入员工新姓名" << endl;
			cin >> name;
			cout << "请选择新岗位" << endl;
			cout << "1.牛马" << endl;
			cout << "2.高级牛马" << endl;
			cout << "3.资本家" << endl;
			cin >> pos;
			worker* wo = NULL;
			while (pos < 1 || pos>3) {
				switch (pos)
				{
				case 1:wo = new normal(id, name, 1);
					break;
				case 2:wo = new manager(id, name, 2);
					break;
				case 3:wo = new boss(id, name, 3);
					break;
				default:
					cout << "输入错误，请重新选择岗位" << endl;
					cout << "1.牛马" << endl;
					cout << "2.高级牛马" << endl;
					cout << "3.资本家" << endl;
					cin >> pos;
					break;
				}

			}

			switch (pos)
			{
			case 1:wo = new normal(id, name, 1);
				break;
			case 2:wo = new manager(id, name, 2);
				break;
			case 3:wo = new boss(id, name, 3);
				break;
			}
			this->mArray[index] = wo;
			this->save();
			cout << "修改成功" << endl;
		}
		else {
			cout << "未能找到员工" << endl;
		}
		cout << "按任意键清屏" << endl;
		system("pause");
		system("cls");
		return;
	}
	void workermanager::serchmen()
	{
		int id = 0;
		cout << "请输入查找员工id" << endl;
		cin >> id;
		int index = this->IsExist(id);
		this->mArray[index]->showinfo();
	}
	void workermanager::delmen()
	{
		cout << "请输入开除职工编号" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1) {
			for (int i = index; i < this->mnum - 1; i++) {
				this->mArray[i] = this->mArray[i + 1];
				}
			this->mnum--;
			this->save();

		}
		else
		{
			cout << "删除失败未找到该id" << endl;
		}
		
	}
	
	void workermanager::addmessage() {
		int addnum = 0;
		cout << "请输入添加人数" << endl;
		cin >> addnum;
		if (addnum > 0) {
			int newsize = this->mnum + addnum;
			worker** newspace = new worker * [newsize];
			if (this->mArray != NULL) {
				for (int i = 0; i < this->mnum; i++) {
					newspace[i] = this->mArray[i];
				}
			}
				for (int i = 0; i < addnum; i++) {
					int id=0;
					string name;
					int pos=0;
					cout << "请输入第" << i + 1 << "个新员工编号" << endl;
					/*ke1:*/ cin >> id;
					
					cout << "请输入第" << i + 1 << "个新员工姓名" << endl;
					cin >> name;
					cout << "请选择"<<endl;
					cout << "1.牛马"  << endl;
					cout << "2.高级牛马" << endl;
					cout << "3.资本家" << endl;
					cin >> pos; 
					worker* wo = NULL;
					while (pos < 1 || pos>3) {
						switch (pos)
						{
						case 1:wo = new normal(id, name, 1);
							break;
						case 2:wo = new manager(id, name, 2);
							break;
						case 3:wo = new boss(id, name, 3);
							break;
						default:
							cout << "输入错误，请重新选择岗位" << endl;
							cout << "1.牛马" << endl;
							cout << "2.高级牛马" << endl;
							cout << "3.资本家" << endl;
							cin >> pos;
							break;
						}

					}
					
				switch (pos)
					{
					case 1:wo = new normal(id, name, 1);
						break;
					case 2:wo = new manager(id, name, 2);
						break;
					case 3:wo = new boss(id, name, 3);
						break;
					}/*if (mArray[i]->id == mArray[i - 1]->id) {
						cout << "重新输入" << endl;
						system("pause");
						goto ke1;
					}*/
					newspace[this->mnum + i] = wo;
				}
				delete[] this->mArray;
				this->mArray = newspace;
				this->mnum = newsize;
				this->fileIsEmpty = false;
				cout << "添加成功" << endl;
				this->save();
					system("pause");
					system("cls");
			}
			else {
				cout << "输入错误请重新输入" << endl;
				system("pause");
				system("cls");
		}
	}