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
// ��ƹ�����
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
	//������һ�ֱ���ѡ��
	vector<int>v1;
	//�ڶ���
	vector<int>v2;
	//������
	vector<int>v3;
	//������
	vector<int>v4;
	//��ű�źͶ�Ӧѡ�ֵĵ�����
	map<int ,player> m_speaker;
	bool fileIsEmpty = true;
	int time=1;
	map<int, vector<string>>rload;
	
};  

