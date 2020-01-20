#include <stdio.h>
#include <math.h>
#include <locale.h>

//Задание выполнил Беспальчук Денис Юрьевич

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

//Задание 3c (с рекурсией + свойство четности степени)
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

	printf("Введите число, которое хотите возвести в степень: \n");
	scanf("%lf", &x);

	printf("Введите степень: \n");
	scanf("%ld", &n);

	printf("%.2lf\n", power(x, n));

	printf("Посчитали с помощью рекурсии и свойством четности степени: %.2lf\n\n", power_rec_even(x, n));
}

/*
Задание 3.
**Исполнитель «Калькулятор» преобразует целое число, записанное на экране. У
исполнителя две команды, каждой присвоен номер:
1. Прибавь 1.
2. Умножь на 2.
Первая команда увеличивает число на экране на 1, вторая увеличивает его в 2 раза. Сколько
существует программ, которые число 3 преобразуют в число 20:
а. С использованием массива.
b. *С использованием рекурсии.
*/

// реализация через массив
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

// реализация с рекурсией
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
	printf("Через массив: %d\n", calc_arr());
	printf("С помощью рекурсии: %d\n\n", calc_rec(20));
}

void menu()
{
	printf("Введите номер задания, которое хотите посмотреть и клавишу Enter\n");
	printf("1 - Задание 1\n");
	printf("2 - Задание 2\n");
	printf("3 - Задание 3\n");
	printf("0 - Exit\n");
}