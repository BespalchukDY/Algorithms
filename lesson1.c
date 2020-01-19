#include <stdio.h>
#include <math.h>
#include <locale.h>

//������� �������� ���������� ����� �������

void task1();
void task2();
void task3();
void task4();
void menu();

int main()
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
			task1(1);
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		case 4:
			task4();
			break;
		case 0:
			printf("����� ��������!\n");
			break;
		default:
			printf("������ ������������ ����� �������!\n");
		}
	} while (sel != 0);
	getch();
	return 0;
}

/* 
������� 1. 
������ ��� � ���� ��������. ���������� � ������� ������ ����� ���� �� ������� I=m/(h*h); 
��� m - ����� ���� � �����������, h - ���� � ������
*/
void task1()
{
	printf("������� 1:\n\n");

	double m = 0, h = 0;

	printf("������� ����� ���� � ����������� (����� ����� �������� �������): \n");
	scanf("%lf", &m);

	printf("������� ���� � ������ (����� ����� �������� �������): \n");
	scanf("%lf", &h);

	double I = m / (h * h);
	printf("������ ����� ���� �����: %.2lf\n\n", I);
}

/*
������� 2.
����� ������������ �� ������� �����. ������� �� ������������.
*/
void task2()
{
	printf("������� 2:\n\n");

	int a, b, c, d;

	printf("������� ������ ������ ����� �����\n");

	printf("������� ������ �����: \n");
	scanf("%i", &a);

	printf("������� ������ �����: \n");
	scanf("%i", &b);

	printf("������� ������ �����: \n");
	scanf("%i", &c);

	printf("������� ��������� �����: \n");
	scanf("%i", &d);

	if (a > b && a > c && a > d)
	{
		printf("������������ �����: %d\n\n", a);
	}
	else if (b > a && b > c && b > d)
	{
		printf("������������ �����: %d\n\n", b);
	}
	else if (c > a && c > b && c > d)
	{
		printf("������������ �����: %d\n\n", c);
	}
	else if (d > a && d > b && d > c)
	{
		printf("������������ �����: %d\n\n", d);
	}
	else printf("�� ����� ���������� ������������ �����!\n\n");

}

/*
������� 3.
�������� ��������� ������ ���������� ���� ������������� ����������:
	a. � �������������� ������� ����������;
	b. *��� ������������� ������� ����������.
*/
void task3()
{
	printf("������� 3:\n\n");
	
	int a, b, c;

	printf("������� ������ �����: \n");
	scanf("%i", &a);

	printf("������� ������ �����: \n");
	scanf("%i", &b);

	printf("�� �����: %d � %d\n\n", a, b);
	
	// ������� ��� �.
	c = a;
	a = b;
	b = c;
	//������� ��� b.
	// a ^= (b^=(a^=b));
	
	printf("�������� �������� ��: %d � %d\n\n", a, b);
}

/*
������� 4.
�������� ��������� ���������� ������ ��������� ����������� ���������.
*/
void task4()
{
	printf("������� 4: \n\n");

	float x, y, z, x1, x2;

	printf("��������� ��������� ����� ����������� ���������: ax^2 + bx + c = 0\n");

	printf("\n������� a: ");
	scanf("%f", &x);
	printf("\n������� b: ");
	scanf("%f", &y);
	printf("\n������� c: ");
	scanf("%f", &z);

	double D; //������������

		D = (y * y) - (4 * x * z);
		
		if (D > 0)
		{
			x1 = (-y + sqrt(D)) / (2 * x);
			x2 = (-y - sqrt(D)) / (2 * x);
			printf("��������� ����� ��� ����� x1 = %f, x2 = %f\n\n", x1, x2);
			return 1;
		}
		else if (D == 0)
		{
			x1 = -y / (2 * x);
			printf("��������� ����� ���� ������ x = %f\n\n", x1);
			return 0;
		}
		else {
			// D < 0;
			printf("��������� �� ����� ������\n\n");

			return -1;
		}
	}


 
void menu()
{
	printf("������� ����� �������, ������� ������ ���������� � ������� Enter \n"); 
	printf("1 - ������� 1\n");
	printf("2 - ������� 2\n");
	printf("3 - ������� 3\n");
	printf("4 - ������� 4\n");
	printf("0 - Exit\n");
}