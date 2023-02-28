#include"workermanager.h"

workermanager::workermanager() {
	//�ļ�������
	ifstream ifs;
	ifs.open(flname, ios::in);//���ļ�
		if (!ifs.is_open()) {
			cout << "�ļ�������" << endl;
			//��ʼ��
		this->mArray = NULL;
		this->mnum = 0;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
		//�ļ����ڵ����޼�¼
		char ch;
		ifs >> ch;
		if (ifs.eof()) {
			cout << "�ļ���Ϊ��" << endl;
			this->fileIsEmpty = true;
			this->mArray = NULL;
			this->mnum = 0;
			ifs.close();
			return;

		}
		int num = this->getnum();
		this->mnum = num;
}
//ͳ���ļ�������
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
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
	
	cout << "����ɹ�" << endl;
	this->save();

	//����׼temp�����Լ���λ�ã�����i��λ�ã�
	
	
}

void workermanager::clean()
{
	cout << "�Ƿ����" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int sel = 0;
	cin >> sel;
	if (sel==1) {
		//�� ios����trunc�������ɾ���ļ����´���
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
	cout << "�����" << endl;
	}system("pause");
	system("cls");
	
}


  

	void workermanager::showmenu(){
		cout << "********************************************" << endl;
		cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
		cout << "*************  0.�˳��������  *************" << endl;
		cout << "*************  1.����ְ����Ϣ  *************" << endl;
		cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
		cout << "*************  3.ɾ����ְְ��  *************" << endl;
		cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
		cout << "*************  5.����ְ����Ϣ  *************" << endl;
		cout << "*************  6.���ձ������  *************" << endl;
		cout << "*************  7.��������ĵ�  *************" << endl;
		cout << "********************************************" << endl;
		cout << endl;
} 
	void workermanager::exitmenu() {
		cout << "��������˳�" << endl;
		system("pause");
		exit(0);
	}
	
	void workermanager::showmessage()
	{
		
			if (this->fileIsEmpty) {
				cout << "�ļ���" << endl;
			}
			else {
				for (int i = 0; i <mnum; i++)
				{
					this->mArray[i]->showinfo();
				}
			
				}
			cout << "�����������" << endl;
			system("pause");
			system("cls");
	}		

		
	
	int workermanager::IsExist(int id) {
	   //���޴���
		int index = -1;
		cout << "���޴���" << endl;
		for (int i = 0; i < this->mnum; i++) {
			if (id == this->mArray[i]->id) {
				index = i;
			}
		}return index;
	}
	void workermanager::changemen()
	{
		//�ҵ���Ҫ�޸ĵ�Ա��
		int id = 0;
		cout << "��������Ҫ�޸�Ա�����" << endl;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1) {
			delete this->mArray[index];
			int id = 0;
			string name;
			int pos = 0;
			cout << "������Ա���±��" << endl;
			cin >> id;
			cout << "������Ա��������" << endl;
			cin >> name;
			cout << "��ѡ���¸�λ" << endl;
			cout << "1.ţ��" << endl;
			cout << "2.�߼�ţ��" << endl;
			cout << "3.�ʱ���" << endl;
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
					cout << "�������������ѡ���λ" << endl;
					cout << "1.ţ��" << endl;
					cout << "2.�߼�ţ��" << endl;
					cout << "3.�ʱ���" << endl;
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
			cout << "�޸ĳɹ�" << endl;
		}
		else {
			cout << "δ���ҵ�Ա��" << endl;
		}
		cout << "�����������" << endl;
		system("pause");
		system("cls");
		return;
	}
	void workermanager::serchmen()
	{
		int id = 0;
		cout << "���������Ա��id" << endl;
		cin >> id;
		int index = this->IsExist(id);
		this->mArray[index]->showinfo();
	}
	void workermanager::delmen()
	{
		cout << "�����뿪��ְ�����" << endl;
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
			cout << "ɾ��ʧ��δ�ҵ���id" << endl;
		}
		
	}
	
	void workermanager::addmessage() {
		int addnum = 0;
		cout << "�������������" << endl;
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
					cout << "�������" << i + 1 << "����Ա�����" << endl;
					/*ke1:*/ cin >> id;
					
					cout << "�������" << i + 1 << "����Ա������" << endl;
					cin >> name;
					cout << "��ѡ��"<<endl;
					cout << "1.ţ��"  << endl;
					cout << "2.�߼�ţ��" << endl;
					cout << "3.�ʱ���" << endl;
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
							cout << "�������������ѡ���λ" << endl;
							cout << "1.ţ��" << endl;
							cout << "2.�߼�ţ��" << endl;
							cout << "3.�ʱ���" << endl;
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
						cout << "��������" << endl;
						system("pause");
						goto ke1;
					}*/
					newspace[this->mnum + i] = wo;
				}
				delete[] this->mArray;
				this->mArray = newspace;
				this->mnum = newsize;
				this->fileIsEmpty = false;
				cout << "��ӳɹ�" << endl;
				this->save();
					system("pause");
					system("cls");
			}
			else {
				cout << "�����������������" << endl;
				system("pause");
				system("cls");
		}
	}