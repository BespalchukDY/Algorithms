#include <stdio.h>
#include <math.h>
#include <locale.h>

//Задание выполнил Беспальчук Денис Юрьевич

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
			printf("Всего хорошего!\n");
			break;
		default:
			printf("Введен некорректный номер задания!\n");
		}
	} while (sel != 0);
	getch();
	return 0;
}

/*
Задание 1.
Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.
*/
void task1()
{
	int n;

	printf("Введите десятичное число: ");
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
Задание 2.
Реализовать функцию возведения числа a в степень b:
a. Без рекурсии.
b. Рекурсивно.
c. *Рекурсивно, используя свойство чётности степени.
*/

//Задание 2a (без рекурсии)
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


//Задание 2b (с рекурсией)

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
	printf("Введите число, которое хотите возвести в степень: \n");
	scanf("%lf", &x);

	printf("Введите степень: \n");
	scanf("%ld", &n);

	printf("%.2lf\n", power(x, n));
}

void menu()
{
	printf("Введите номер задания, которое хотите посмотреть и клавишу Enter\n");
	printf("1 - Задание 1\n");
	printf("2 - Задание 2\n");
	printf("0 - Exit\n");
}