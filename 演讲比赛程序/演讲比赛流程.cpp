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
		cout << "���������ѡ��" << endl;
		cin >> i;
		while (cin.fail())
		{
		cin.clear();//���cin�Ĵ�����Ϣ
		cin.ignore();//���Ե�������������,����EOFλ��
		cout << "��������ȷ�����֣����ͣ�:";
		cin.ignore();//EOFλ�ã�������һ��cin����
		cin >> i;
		}
		switch (i)
		{
		
		
		case 1://��ʼ����
			s.startmatch();
			break;

		case 2://�鿴�����¼
			s.showpast();
			break;

		case 3://��ձ�����¼
			s.cleanroad();
			break;
		case 4://�˳���������
			s.exitsystem();
			break;
		default:
			system("cls");
			break;
		}
		
	}






	return 0;
}