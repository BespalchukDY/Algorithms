#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <locale.h>

//Задание выполнил Беспальчук Денис Юрьевич

int* AllElements;
int ArraySize;
int SearchValue;

void massive();

void task1();
void swap(int* AllElements, int* b);
void print(int ArraySize, int* AllElements);

void task2();
void ShakerSort(int* AllElements, int ArraySize);

int task3();
int binarysearch(int ArraySize, int AllElements[], int SearchValue);

void task4();

void menu();

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
	_getch();
	return 0;
}

void massive() // Функция создания и вывода на экран массива сгенерированного из случайных чисел
{

	int i;
	printf("Введите размер массива: ");
	scanf("%d", &ArraySize);
	printf("\n");
	srand(time(NULL));
	AllElements = malloc(ArraySize * sizeof(int));

	printf("Сгенерированный массив:\n");
	for (i = 0; i < ArraySize; i++)
	{
		AllElements[i] = rand() % 101;
		printf("%d ", AllElements[i]);
	}
	printf("\n");
}

/*
Задание 1.
Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения
оптимизированной и не оптимизированной программы. Написать функции сортировки, которые
возвращают количество операций.
*/

void swap(int *AllElements, int *b) // Функция перемещения
{
	int  t = *AllElements;
	*AllElements = *b;
	*b = t;
}

void print(int ArraySize, int* AllElements) // Функция печати массива
{
	int i;
	for (i = 0; i < ArraySize; i++)
	{
		printf("%i ", AllElements[i]);
	}
	printf("\n");
}

void sort(int ArraySize, int* AllElements) // Обычная пузырьковая сортировка
{
	int i;
	int j = 0;
	int count1 = 0;

	for (i = 0; i < ArraySize; i++)
	{
		for (j = 0; j < ArraySize - 1; j++)
		{
			count1++;
			if (AllElements[j] > AllElements[j + 1])
			{
				count1++;
				swap(&AllElements[j], &AllElements[j + 1]);
			}
		}
	}
	printf("\nМассив после пузырьковой сортировки:\n");
	print(ArraySize, AllElements);
	printf("\n");
	printf("Счётчик количества операций равен: %d\n", count1);
}

void sortopt(int ArraySize, int* AllElements, bool asc) // Оптимизированная пузырьковая сортировка
{
	int i = 0;
	int j = 0;
	int count2 = 0;

	for (i = 0; i < ArraySize - 1; i++)
	{
		for (j = i + 1; j < ArraySize; j++)
		{
			count2++;
			if ((asc && AllElements[i] > AllElements[j]) || (!asc && AllElements[i] < AllElements[j]))
			{
				count2++;
				int tmp = AllElements[i];
				AllElements[i] = AllElements[j];
				AllElements[j] = tmp;
			}
		}
	}
	printf("\nМассив после оптимизированной пузырьковой сортировки:\n");
	print(ArraySize, AllElements);
	printf("\n");
	printf("Счётчик количества операций после оптимизированной пузырьковой сортировки равен: %d\n", count2);
}

// Задание 1.

void task1()
{
	printf("Задание №1\n");
	printf("Попробовать оптимизировать пузырьковую сортировку и т.д.\n");
	
	int i;

	massive(AllElements, ArraySize);

	sort(ArraySize, AllElements);

	sortopt(ArraySize, AllElements, true);
}

/*
Задание 2.
Реализовать шейкерную сортировку.
*/

void ShakerSort(int* AllElements, int ArraySize) // Функция шейкерной сортировки
{
	int left = 0;
	int right = ArraySize - 1;
	int count3 = 0;
	int flag = 1;

	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int j = left; j < right; j++)
		{
			count3++;
			if (AllElements[j] > AllElements[j + 1])
			{
				int tmp = AllElements[j];
				AllElements[j] = AllElements[j + 1];
				AllElements[j + 1] = tmp;
				flag = 1;
			}
		}
		right--;

		for (int j = right; j > left; j--)
		{
			count3++;
			if (AllElements[j - 1] > AllElements[j])
			{
				int tmp = AllElements[j];
				AllElements[j] = AllElements[j - 1];
				AllElements[j - 1] = tmp;
				flag = 1;
			}
		}
		left++;
	}

	printf("\nМассив после шейкерной сортировки:\n");
	print(ArraySize, AllElements);
	printf("\n");
	printf("Счётчик количества операций после шейкерной сортировки равен: %d\n\n", count3);
}

// Задание 2.
void task2()
{
	printf("Задание №2\n");
	printf("Реализовать шейкерную сортировку\n");

	massive(AllElements, ArraySize);

	ShakerSort(AllElements, ArraySize);

}

/*
Задание 3.
Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный
массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден.
*/

int task3()
{
	printf("Задание №3\n");
	printf("Реализовать бинарный алгоритм поиска в виде функции\n");

	int Middle;
	int k;
	int cip;

	printf("Введите размер массива:");
	scanf("%d", &ArraySize);

	AllElements = (int*)malloc(ArraySize * sizeof(int));
	cip = 0;
	for (int j = 0; j < ArraySize; j++) {
		AllElements[j] = cip;
		cip++;
	}

	printf("Введите значение для поиска:");
	scanf("%d", &SearchValue);

	printf("Отсортированный массив:\n");
	for (int i = 0; i < ArraySize; i++)
		printf("%d ", AllElements[i]);
	printf("\n");

	k = binarysearch(ArraySize, AllElements, SearchValue);
	if (k != -1)
	{
		printf("Индекс:%d", k);
		printf("\n");
	}
	else
		printf("Значение не найдено");
	printf("\n");
	free(AllElements);

}

int binarysearch(int ArraySize, int AllElements[], int SearchValue) // Функция бинарного поиска
{
	int Low;
	int High;
	int Middle;

	Low = 0;
	High = ArraySize - 1;

	while (Low <= High)
	{
		Middle = (Low + High) / 2;
		if (SearchValue < AllElements[Middle])
		{
			High = Middle - 1;
		}
		else if (SearchValue > AllElements[Middle])
		{
			Low = Middle + 1;
		}
		else
			return Middle;
	}
	return -1;
}

/*Задание 4.
Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической
сложностью алгоритма
*/
void task4()
{
	printf("\nЗадание №4\n");
	printf("Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма\n");

	int i;

	massive(AllElements, ArraySize);

	sort(ArraySize, AllElements);

	sortopt(ArraySize, AllElements, true);
	
	ShakerSort(AllElements, ArraySize);

	int j = 0;
	int jmin;
	int count4 = 0;
	int count5 = 0;

	// Сортировка методом выбора
	for (i = 0; i < ArraySize; i++)
	{
		jmin = i;
		for (j = i + 1; j < ArraySize; j++)
		{
			count4++; 
			if (AllElements[j] < AllElements[jmin])
			{
				jmin = j; 
			}
		}
		swap(&AllElements[i], &AllElements[jmin]);
	}

	puts("Массив после сортировки методом выбора");
	print(ArraySize, AllElements);
	printf("\n");
	printf("Счётчик количества операций после сортировки методом выбора равен: %d\n\n", count4);

	// Сортировка вставками
	for (i = 0; i < ArraySize; i++)
	{
		count5++; 
		int tmp = AllElements[i];
		int j = i;
		while (j > 0 && AllElements[j - 1] > tmp)
		{
			swap(&AllElements[j], &AllElements[j - 1]);
			j--;
		}
	}
	print(ArraySize, AllElements);
	printf("\n");
	printf("Счётчик количества операций после сортировки вставками равен: %d\n\n", count5);
	printf("\n");
}

void menu()
{
	printf("Введите номер задания, которое хотите посмотреть и клавишу Enter\n");
	printf("1 - Задание 1\n");
	printf("2 - Задание 2\n");
	printf("3 - Задание 3\n");
	printf("4 - Задание 4\n");
	printf("0 - Exit\n");
}