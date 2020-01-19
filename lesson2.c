#include <stdio.h>
#include <math.h>
#include <locale.h>

//������� �������� ���������� ����� �������

void task1();
void task2();
void task3();
void menu();
void Func(int n);
double power(double x, long n);


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
����������� ������� �������� ����� �� ���������� ������� � ��������, ��������� ��������.
*/
void task1()
{
		int n;

		printf("������� ���������� �����: ");
		scanf("%d", &n);

		Func(n);
		printf("\n");
		return 0;
}

void Func(int n) {

	if (n != 0)
		Func(n / 2);
	else return;
	printf("%d", n % 2);
	return;
}

/*
������� 2.
����������� ������� ���������� ����� a � ������� b:
a. ��� ��������.
b. ����������.
c. *����������, ��������� �������� �������� �������.
*/


//������� 2 (��� ��������)


double power(double x, long n)
{
	double a = 1;
	while (n) {
		if (n % 2) {
			a *= x;
			n--;
		}
		else {
			x *= x;
			n /= 2;
		}
	}
	return a;
}



//������� 2 (� ���������)
/*
double power(double x, long n)
{
	double tmp;
	if (n == 0) return 1;
	if (n < 0) return power(1 / x, -n);
	if (n % 2) return x * power(x, n - 1);
	return power(x * x, n / 2);
}
*/

void task2()
{
	double x;
	long n;
	printf("������� �����, ������� ������ �������� � �������: \n");
	scanf("%lf", &x);

	printf("������� �������: \n");
	scanf("%ld", &n);

	printf("%16.3lf\n", power(x, n));
}

/*
������� 3.
**����������� ������������ ����������� ����� �����, ���������� �� ������. �
����������� ��� �������, ������ �������� �����:
1. ������� 1.
2. ������ �� 2.
������ ������� ����������� ����� �� ������ �� 1, ������ ����������� ��� � 2 ����. �������
���������� ��������, ������� ����� 3 ����������� � ����� 20:
�. � �������������� �������.
b. *� �������������� ��������.
*/
void task3()
{

}

void menu()
{
	printf("������� ����� �������, ������� ������ ���������� � ������� Enter\n");
	printf("1 - ������� 1\n");
	printf("2 - ������� 2\n");
	printf("3 - ������� 3\n");
	printf("0 - Exit\n");
}