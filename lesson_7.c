#include "Modules.h"
#include <locale.h>

//������� �������� ���������� ����� �������

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");
	int sel = 0;

	do
	{
		menu();
		scanf("%i", &sel);
		switch (sel)
		{
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		case 0:
			printf("����� ��������!\n");
			break;
		default:
			printf("������ ������������ ����� �������!\n");
		}
	} while (sel != 0);
	_getch();
	return 0;
}