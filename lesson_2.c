#include <stdio.h>
#include <math.h>
#include <locale.h>

//������� �������� ���������� ����� �������

void task1();
void task2();
void menu();
void DecBin(int n);
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

	DecBin(n);
	printf("\n");
}

void DecBin(int n) {

	if (n != 0)
		DecBin(n / 2);

	printf("%d", n % 2);
}

/*
������� 2.
����������� ������� ���������� ����� a � ������� b:
a. ��� ��������.
b. ����������.
c. *����������, ��������� �������� �������� �������.
*/

//������� 2a (��� ��������)
/*
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
*/


//������� 2b (� ���������)

double power(double x, long n)
{
	if (n == 0) return 1;
	if (n < 0) return power(1 / x, -n);
	if (n % 2) return x * power(x, n - 1);
	return power(x * x, n / 2);
}


void task2()
{
	double x;
	long n;
	printf("������� �����, ������� ������ �������� � �������: \n");
	scanf("%lf", &x);

	printf("������� �������: \n");
	scanf("%ld", &n);

	printf("%.2lf\n", power(x, n));
}

void menu()
{
	printf("������� ����� �������, ������� ������ ���������� � ������� Enter\n");
	printf("1 - ������� 1\n");
	printf("2 - ������� 2\n");
	printf("0 - Exit\n");
}