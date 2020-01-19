#include <stdio.h>
#include <math.h>
#include <locale.h>

//Задание выполнил Беспальчук Денис Юрьевич

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
Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); 
где m - масса тела в килограммах, h - рост в метрах
*/
void task1()
{
	printf("Задание 1:\n\n");

	double m = 0, h = 0;

	printf("Введите массу тела в килограммах (целую часть отделите запятой): \n");
	scanf("%lf", &m);

	printf("Введите рост в метрах (целую часть отделите запятой): \n");
	scanf("%lf", &h);

	double I = m / (h * h);
	printf("Индекс массы телы равен: %.2lf\n\n", I);
}

/*
Задание 2.
Найти максимальное из четырех чисел. Массивы не использовать.
*/
void task2()
{
	printf("Задание 2:\n\n");

	int a, b, c, d;

	printf("Введите четыре разных целых числа\n");

	printf("Введите первое число: \n");
	scanf("%i", &a);

	printf("Введите второе число: \n");
	scanf("%i", &b);

	printf("Введите третье число: \n");
	scanf("%i", &c);

	printf("Введите четвертое число: \n");
	scanf("%i", &d);

	if (a > b && a > c && a > d)
	{
		printf("Максимальное число: %d\n\n", a);
	}
	else if (b > a && b > c && b > d)
	{
		printf("Максимальное число: %d\n\n", b);
	}
	else if (c > a && c > b && c > d)
	{
		printf("Максимальное число: %d\n\n", c);
	}
	else if (d > a && d > b && d > c)
	{
		printf("Максимальное число: %d\n\n", d);
	}
	else printf("Вы ввели одинаковые максимальные числа!\n\n");

}

/*
Задание 3.
Написать программу обмена значениями двух целочисленных переменных:
	a. с использованием третьей переменной;
	b. *без использования третьей переменной.
*/
void task3()
{
	printf("Задание 3:\n\n");
	
	int a, b, c;

	printf("Введите первое число: \n");
	scanf("%i", &a);

	printf("Введите второе число: \n");
	scanf("%i", &b);

	printf("Вы ввели: %d и %d\n\n", a, b);
	
	// Решение для а.
	c = a;
	a = b;
	b = c;
	//Решение для b.
	// a ^= (b^=(a^=b));
	
	printf("Поменяли значения на: %d и %d\n\n", a, b);
}

/*
Задание 4.
Написать программу нахождения корней заданного квадратного уравнения.
*/
void task4()
{
	printf("Задание 4: \n\n");

	float x, y, z, x1, x2;

	printf("Программа посчитает корни квадратного уравнения: ax^2 + bx + c = 0\n");

	printf("\nВведите a: ");
	scanf("%f", &x);
	printf("\nВведите b: ");
	scanf("%f", &y);
	printf("\nВведите c: ");
	scanf("%f", &z);

	double D; //Дискриминант

		D = (y * y) - (4 * x * z);
		
		if (D > 0)
		{
			x1 = (-y + sqrt(D)) / (2 * x);
			x2 = (-y - sqrt(D)) / (2 * x);
			printf("Уравнение имеет два корня x1 = %f, x2 = %f\n\n", x1, x2);
			return 1;
		}
		else if (D == 0)
		{
			x1 = -y / (2 * x);
			printf("Уравнение имеет один корень x = %f\n\n", x1);
			return 0;
		}
		else {
			// D < 0;
			printf("Уравнение не имеет корней\n\n");

			return -1;
		}
	}


 
void menu()
{
	printf("Введите номер задания, которое хотите посмотреть и клавишу Enter \n"); 
	printf("1 - Задание 1\n");
	printf("2 - Задание 2\n");
	printf("3 - Задание 3\n");
	printf("4 - Задание 4\n");
	printf("0 - Exit\n");
}