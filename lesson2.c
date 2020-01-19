#include <stdio.h>
#include <math.h>
#include <locale.h>

//Задание выполнил Беспальчук Денис Юрьевич

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
Задание 2.
Реализовать функцию возведения числа a в степень b:
a. Без рекурсии.
b. Рекурсивно.
c. *Рекурсивно, используя свойство чётности степени.
*/


//Задание 2 (без рекурсии)


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



//Задание 2 (с рекурсией)
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
	printf("Введите число, которое хотите возвести в степень: \n");
	scanf("%lf", &x);

	printf("Введите степень: \n");
	scanf("%ld", &n);

	printf("%16.3lf\n", power(x, n));
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
void task3()
{

}

void menu()
{
	printf("Введите номер задания, которое хотите посмотреть и клавишу Enter\n");
	printf("1 - Задание 1\n");
	printf("2 - Задание 2\n");
	printf("3 - Задание 3\n");
	printf("0 - Exit\n");
}