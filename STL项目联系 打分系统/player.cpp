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
		string name = "ѡ��";
		name += nameseed[i];//ƴ������
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
	cout << "ѡ��" << it->name << "�÷� "<< endl;
	for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
		cout << *dit << "  ";
	}cout << endl ;

	sort(d.begin(), d.end());
	//ȥ�������ͷ�
	d.pop_front();
	d.pop_back();
	//ȡƽ����
	int sum = 0;
	for (deque<int>::iterator di = d.begin(); di != d.end(); di++) {
		sum += *di;
	}
		int avg = sum / d.size();
	//ƽ���ָ�ֵ
		it->socre = avg;
	}
 }
void show(vector<player>& p) {
	for (vector<player>::iterator it = p.begin(); it != p.end(); it++) {
		cout << it->name << endl << "����";
		cout << it->socre << endl;;
	}
}

int main() {
	srand((unsigned int)time(NULL));
	//����ѡ��
	vector<player>(v);
	create(v);
	//���
	set(v);
	//չʾ����
	show(v);
}