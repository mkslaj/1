#include "player.h"
#include "speech.h"
#include<ctime>
int main() {
	speech s;
	while (true)
	{
		srand((unsigned int)time(NULL));
		s.showmenu();
		int i = 0;
		cout << "请输入你的选择" << endl;
		cin >> i;
		while (cin.fail())
		{
		cin.clear();//清除cin的错误信息
		cin.ignore();//忽略掉缓冲区的内容,置于EOF位置
		cout << "请输入正确的数字（整型）:";
		cin.ignore();//EOF位置，接收下一个cin函数
		cin >> i;
		}
		switch (i)
		{
		
		
		case 1://开始比赛
			s.startmatch();
			break;

		case 2://查看往届记录
			s.showpast();
			break;

		case 3://清空比赛记录
			s.cleanroad();
			break;
		case 4://退出比赛程序
			s.exitsystem();
			break;
		default:
			system("cls");
			break;
		}
		
	}






	return 0;
}