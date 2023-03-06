#include "speech.h"
#pragma once

speech::speech()
{
	//初始化属性
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
		string na = "选手";
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
//抽签
void speech::randomnum()
{
	cout << "第<<" << this->time << ">>轮比赛选手正在抽签" << endl;
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
	cout << "------第" << this->time << "轮比赛开始" << endl;
	//临时容器存放小组成绩
	multimap<double, int, greater<double>> gsocre;
	int num = 0;//记录人数 ，6个一组
	vector<int>v;
	if(this->time==1)
	{
		v = v1;
	}
	else
	{
		v = v2;
	}
	//遍历选手打分
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
		cout << " 编号 "<<*it <<"  姓名 "<<this->m_speaker[*it].name << "  平均分 " << avg << endl;
		//放入map
		this->m_speaker[*it].socre[this->time - 1] = avg;
		//小组成绩放入临时容器
		gsocre.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << num / 6 << "小组" << endl;
			for (multimap<double, int, greater<double>>::iterator it = gsocre.begin(); it != gsocre.end();it++) 
			{
				cout << "编号" << it->second << "姓名" 
					<< this->m_speaker[it->second].name << "分数" 
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
	cout << this->time << "轮比赛完毕" << endl;
	system("pause");
}
void speech::showsocre()
{
	cout << this->time << "轮晋级选手信息如下" << endl;
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
		cout << "编号" << *it << "名字" << m_speaker[*it].name << "得分" << m_speaker[*it].socre[this->time-1] << endl;
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
	cout << "已保存" << endl;
	this->fileIsEmpty = false;
}
void speech::startmatch()
{
	//抽签
	this->randomnum();
	//开始
	this->contest();
	this->showsocre();
	this->time++;
	this->randomnum();
	this->createplayer();

	//开始
	this->contest();
	this->showsocre();
	//保存分数
	this->save();
	this->load();
	cout << "比赛结束" << endl;
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
		cout << "无文件" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) 
	{
		cout << "无记录" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	this->fileIsEmpty = false;
	ifs.putback(ch);//将上面读取的字符放回来
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
			string tmp = data.substr(start, pos - start);//参数1起始位置，参数2 截取长度
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
		cout << "无记录" << endl;
	}
	else 
	{
		//遍历存在数组位置错位BUG
		for (int i=0;i<this->rload.size();i++) 
		{
		cout << "第" << i+1 << "届" << endl;
		cout << "冠军编号" <<this->rload[i][0] << "分数" << this->rload[i][1] << endl;
		cout << "亚军编号" << this->rload[i][2] << "分数" << this->rload[i][3] << endl;
		cout << "季军编号" << this->rload[i][4] << "分数" << this->rload[i][5] << endl;
		}
	}
	
	system("pause");
	system("cls");
}	
void speech::cleanroad() 
{
	cout << "是否清空" << endl;
	cout << "1.是   2.否" << endl;
	int num = 0;
	cin >> num;
	while (cin.fail())
	{
		cin.clear();//清除cin的错误信息
		cin.ignore();//忽略掉缓冲区的内容,置于EOF位置
		cout << "请输入正确的数字（整型）:";
		cin.ignore();//EOF位置，接收下一个cin函数
		cin >> num;
	}
	if (num == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);//打开ios：：trunc 存在文件就删除
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
	cout << "******************  欢迎参加演讲比赛  *****************" << endl;
	cout << "******************  1.开始演讲比赛  ******************" << endl;
	cout << "******************  2.查看往届记录  *****************" << endl;
	cout << "******************  3.清空比赛记录  *****************" << endl;
	cout << "******************  4.退出比赛程序  *****************" << endl;
	cout << "******************  欢迎参加演讲比赛  *****************" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
}

void speech::exitsystem() 
{
	cout << "是否退出" << endl;
	cout << "1.是   2.否" << endl;
	int num = 0;
	cin >> num;
	while (cin.fail())
	{
		cin.clear();//清除cin的错误信息
		cin.ignore();//忽略掉缓冲区的内容,置于EOF位置
		cout << "请输入正确的数字（整型）:";
		cin.ignore();//EOF位置，接收下一个cin函数
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