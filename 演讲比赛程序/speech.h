#pragma once
#include<iostream>
#include"player.h"
using namespace std;
#include<vector>
#include<map>
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<fstream>
// 设计管理类
class speech {
public:
	speech();
	void intispeech();

	void createplayer();

	void randomnum();

	void contest();

	void showsocre();

	void save();

	void startmatch();

	void load();

	void showpast();

	void cleanroad();

	void showmenu();
	void exitsystem();
	~speech();
	//保留第一轮比赛选手
	vector<int>v1;
	//第二轮
	vector<int>v2;
	//第三轮
	vector<int>v3;
	//第四轮
	vector<int>v4;
	//存放编号和对应选手的的容器
	map<int ,player> m_speaker;
	bool fileIsEmpty = true;
	int time=1;
	map<int, vector<string>>rload;
	
};  

