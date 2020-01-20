#include <stdio.h>
#include <math.h>
#include <locale.h>

//������� �������� ���������� ����� �������

void task1();
void DecBin(int n);

void task2();
double power(double x, long n);
double power_rec_even(double x, long n);

void task3();
int calc_arr(void);
int calc_rec(int);

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

//������� 3c (� ��������� + �������� �������� �������)
double power_rec_even(double x, long n) {
	long p = 1;

	if (n == 0) {
		return 1;
	}

	if (n % 2 == 0) {
		p = power_rec_even(x, n / 2);
		return p * p;
	}
	else {
		return x * power_rec_even(x, n - 1);
	}

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

	printf("��������� � ������� �������� � ��������� �������� �������: %.2lf\n\n", power_rec_even(x, n));
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

// ���������� ����� ������
int calc_arr(void) {
	int a[21];
	int i;

	a[2] = 0;
	a[3] = 1;

	for (i = 4; i < 21; i++) {
		if (i % 2 == 0) {
			a[i] = a[i - 1] + a[i / 2];
		}
		else {
			a[i] = a[i - 1];
		}
	}

	return a[20];
}

// ���������� � ���������
int calc_rec(int i) {
	if (i == 2) return 0;
	if (i == 3) return 1;
	if (i % 2 == 0) {
		return calc_rec(i - 1) + calc_rec(i / 2);
	}
	else {
		return calc_rec(i - 1);
	}
}

void task3()
{
	printf("����� ������: %d\n", calc_arr());
	printf("� ������� ��������: %d\n\n", calc_rec(20));
}

void menu()
{
	printf("������� ����� �������, ������� ������ ���������� � ������� Enter\n");
	printf("1 - ������� 1\n");
	printf("2 - ������� 2\n");
	printf("3 - ������� 3\n");
	printf("0 - Exit\n");
}