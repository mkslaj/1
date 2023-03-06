#include"player.h"

player::player(string name, int socre)
{
	this->name = name;
	this->socre = socre;
}

player::~player()
{
}
void create(vector<player>& v) {
	string nameseed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name = "选手";
		name += nameseed[i];//拼接姓名
		int socre = 0;
		player p(name, socre);
		v.push_back(p);
	}
}
	
void set(vector<player>& v) {
	deque<int>d;
	for(vector<player>::iterator it=v.begin();it!=v.end();it++){
	for (int i = 0; i < 10; i++) {
		int socre = rand() % 41 + 60;
		d.push_back(socre);
		}
	cout << "选手" << it->name << "得分 "<< endl;
	for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
		cout << *dit << "  ";
	}cout << endl ;

	sort(d.begin(), d.end());
	//去掉最高最低分
	d.pop_front();
	d.pop_back();
	//取平均分
	int sum = 0;
	for (deque<int>::iterator di = d.begin(); di != d.end(); di++) {
		sum += *di;
	}
		int avg = sum / d.size();
	//平均分赋值
		it->socre = avg;
	}
 }
void show(vector<player>& p) {
	for (vector<player>::iterator it = p.begin(); it != p.end(); it++) {
		cout << it->name << endl << "均分";
		cout << it->socre << endl;;
	}
}

int main() {
	srand((unsigned int)time(NULL));
	//创建选手
	vector<player>(v);
	create(v);
	//打分
	set(v);
	//展示均分
	show(v);
}