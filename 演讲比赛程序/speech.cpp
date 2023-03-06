#include "speech.h"
#pragma once

speech::speech()
{
	//��ʼ������
	this->intispeech();
	this->createplayer();
	this->load();
}
void speech::intispeech() 
{
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->v4.clear();
	this->time = 1;
	this->rload.clear();
}
void speech::createplayer()
{
	string name = "ABCDEFGHIJKL";
	for (int i = 0; i < name.size(); i++) 
	{
		string na = "ѡ��";
		na += name[i];
		player p;
		p.name = na;
		for(int i=0;i<2;i++)
		{
			p.socre[i] = 0;
		}
		this->v1.push_back(i + 10001);
		this->m_speaker.insert(make_pair(i + 10001, p));
	}
}
//��ǩ
void speech::randomnum()
{
	cout << "��<<" << this->time << ">>�ֱ���ѡ�����ڳ�ǩ" << endl;
	if(this->time==1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
			cout << *it << " ";
			cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
			
}
void speech::contest()
{
	cout << "------��" << this->time << "�ֱ�����ʼ" << endl;
	//��ʱ�������С��ɼ�
	multimap<double, int, greater<double>> gsocre;
	int num = 0;//��¼���� ��6��һ��
	vector<int>v;
	if(this->time==1)
	{
		v = v1;
	}
	else
	{
		v = v2;
	}
	//����ѡ�ִ��
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		num++;///
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			
			double socre=(rand()%601+400)/10.f;
			/*cout << socre << "  ";*/
			d.push_back(socre);
		}
		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / d.size();
		cout << " ��� "<<*it <<"  ���� "<<this->m_speaker[*it].name << "  ƽ���� " << avg << endl;
		//����map
		this->m_speaker[*it].socre[this->time - 1] = avg;
		//С��ɼ�������ʱ����
		gsocre.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << num / 6 << "С��" << endl;
			for (multimap<double, int, greater<double>>::iterator it = gsocre.begin(); it != gsocre.end();it++) 
			{
				cout << "���" << it->second << "����" 
					<< this->m_speaker[it->second].name << "����" 
					<< this->m_speaker[it->second].socre[this->time-1 ] << endl;
			}
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = gsocre.begin(); it != gsocre.end() && count < 3; it++, count++) 
			{
				if (this->time == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					v4.push_back((*it).second);
				}
			}
			gsocre.clear();
			cout << endl;
		} 
	}
	cout << this->time << "�ֱ������" << endl;
	system("pause");
}
void speech::showsocre()
{
	cout << this->time << "�ֽ���ѡ����Ϣ����" << endl;
	vector<int>f;
	if (this->time == 1) 
	{
		f = v2;
	}
	else
	{
		f = v4;
	}
	for (vector<int>::iterator it = f.begin(); it != f.end(); it++)
	{
		cout << "���" << *it << "����" << m_speaker[*it].name << "�÷�" << m_speaker[*it].socre[this->time-1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->showmenu();
}
void speech::save()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = v4.begin(); it != v4.end(); it++) 
	{
		ofs << *it << " ,"
			<< m_speaker[*it].socre[1] << " , ";
	}
	ofs << endl;
	ofs.close();
	cout << "�ѱ���" << endl;
	this->fileIsEmpty = false;
}
void speech::startmatch()
{
	//��ǩ
	this->randomnum();
	//��ʼ
	this->contest();
	this->showsocre();
	this->time++;
	this->randomnum();
	this->createplayer();

	//��ʼ
	this->contest();
	this->showsocre();
	//�������
	this->save();
	this->load();
	cout << "��������" << endl;
	this->intispeech();
	system("pause");
	system("cls");

}

void speech::load()
{
	ifstream ifs;
	ifs.open("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "���ļ�" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) 
	{
		cout << "�޼�¼" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	this->fileIsEmpty = false;
	ifs.putback(ch);//�������ȡ���ַ��Ż���
	string data;
	int time = 0;
	while (ifs>>data)
	{
		vector<string>v;
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			string tmp = data.substr(start, pos - start);//����1��ʼλ�ã�����2 ��ȡ����
			v.push_back(tmp);
			start = pos + 1;
		}
		this->rload.insert(make_pair(time, v));
		time++;
	}
	ifs.close();
}
void speech::showpast()
{
	if (this->fileIsEmpty)
	{
		cout << "�޼�¼" << endl;
	}
	else 
	{
		//������������λ�ô�λBUG
		for (int i=0;i<this->rload.size();i++) 
		{
		cout << "��" << i+1 << "��" << endl;
		cout << "�ھ����" <<this->rload[i][0] << "����" << this->rload[i][1] << endl;
		cout << "�Ǿ����" << this->rload[i][2] << "����" << this->rload[i][3] << endl;
		cout << "�������" << this->rload[i][4] << "����" << this->rload[i][5] << endl;
		}
	}
	
	system("pause");
	system("cls");
}	
void speech::cleanroad() 
{
	cout << "�Ƿ����" << endl;
	cout << "1.��   2.��" << endl;
	int num = 0;
	cin >> num;
	while (cin.fail())
	{
		cin.clear();//���cin�Ĵ�����Ϣ
		cin.ignore();//���Ե�������������,����EOFλ��
		cout << "��������ȷ�����֣����ͣ�:";
		cin.ignore();//EOFλ�ã�������һ��cin����
		cin >> num;
	}
	if (num == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);//��ios����trunc �����ļ���ɾ��
		ofs.close();
	}
	this->intispeech();
	this->load();
}

speech::~speech()
{
	
}

void speech::showmenu()
{
	cout << "**************************************************" << endl;
	cout << "******************  ��ӭ�μ��ݽ�����  *****************" << endl;
	cout << "******************  1.��ʼ�ݽ�����  ******************" << endl;
	cout << "******************  2.�鿴�����¼  *****************" << endl;
	cout << "******************  3.��ձ�����¼  *****************" << endl;
	cout << "******************  4.�˳���������  *****************" << endl;
	cout << "******************  ��ӭ�μ��ݽ�����  *****************" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
}

void speech::exitsystem() 
{
	cout << "�Ƿ��˳�" << endl;
	cout << "1.��   2.��" << endl;
	int num = 0;
	cin >> num;
	while (cin.fail())
	{
		cin.clear();//���cin�Ĵ�����Ϣ
		cin.ignore();//���Ե�������������,����EOFλ��
		cout << "��������ȷ�����֣����ͣ�:";
		cin.ignore();//EOFλ�ã�������һ��cin����
		cin >>num;
	}
	if (num == 1) 
	{ 
		exit(0); 
	}
	else
	{
		system("cls");
		return;
	}
		
}