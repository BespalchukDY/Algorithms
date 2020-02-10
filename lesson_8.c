#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

#define CMP_LT(a, b) ((a) < (b))

#define n 10

//Задание выполнил Беспальчук Денис Юрьевич

int task1();
void simpleCountingSort(int *A);

int task2();
void quickSort(int* numbers, int left, int right);

int task3();
void Merge(int *m, int l, int r);
void MergeSort(int* m, int l, int r);

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

/*
Задание 1.
Реализовать сортировку подсчетом
*/

int task1()
{
	printf("Задание №1\n");
	printf("Реализовать сортировку подсчетом\n");
	
	int A[n];

	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 20 - 10;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}

	printf("\n");
	simpleCountingSort(A);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}

	printf("\n\n");
	return 0;
}

void simpleCountingSort(int *A)
{
	int i, j, b;
	int C[n];
	for (i = 0; i < n; i++)
		C[i] = 0;
	for (i = 0; i < 1000; i++)
		C[A[i]]++;
		b = 0;
	for (j = 0; j < n; j++)
		for (i = 0; i < C[j] - 1; i++)
			A[b++] = j;
}


/*
Задание 2.
Реализовать быструю сортировку
*/

void quickSort(int* numbers, int left, int right)
{
	int pivot;
	int l_hold = left;
	int r_hold = right;
	pivot = numbers[left];

	while (left < right)
	{
		while ((numbers[right] >= pivot) && (left < right))
		{
			right--;
		}

		if (left != right)
		{
			numbers[left] = numbers[right];
			left++;
		}

		while ((numbers[left] <= pivot) && (left < right))
		{
			left++;
		}

		if (left != right)
		{
			numbers[right] = numbers[left];
			right--;
		}
	}
	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;

	if (left < pivot)
	{
		quickSort(numbers, left, pivot - 1);
	}

	if (right > pivot)
	{
		quickSort(numbers, pivot + 1, right);
	}
}

int task2()
{
	printf("Задание №2\n");
	printf("Реализовать быструю сортировку\n");

	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 20 - 10;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
	quickSort(a, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n\n");
	return 0;
}

/*
Задание 3.
Реализовать сортировку слиянием
*/


void Merge(int* m, int l, int r)
{
	int i, j, k;
	i = j = k = 0;
	while (i < n && j < m)
	{
		if (CMP_LT(m[i], m[j]))
		{
			m[k++] = m[i++];
		}
		else
		{
			m[k++] = m[j++];
		}
	}
	while (i < n)
	{
		m[k++] = m[i++];
	}
	while (j < m)
	{
		m[k++] = m[j++];
	}
}

void MergeSort(int* m, int l, int r)
{
	int t;
	if (l < r)
		if (r - l == 1)
		{
			if (m[r] < m[l])
			{
				t = m[l];
				m[l] = m[r];
				m[r] = t;
			}
		}
		else
		{
			MergeSort(m, l, l + (r - l) / 2);
			MergeSort(m, r + (r - l) / 2 + 1, r);
			Merge(m, l, r);
		}
}

int task3()
{
	printf("Задание №3\n");
	printf("Реализовать сортировку слиянием\n");

	int m[10];
	for (int i = 0; i < 10; i++)
	{
		m[i] = rand() % 20 - 10;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", m[i]);
	}

	printf("\n");
	quickSort(m, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", m[i]);
	}

	printf("\n\n");
	return 0;
}

void menu()
{
	printf("Введите номер задания, которое хотите посмотреть и клавишу Enter\n");
	printf("1 - Задание 1\n");
	printf("2 - Задание 2\n");
	printf("3 - Задание 3\n");
	printf("0 - Exit\n");
}