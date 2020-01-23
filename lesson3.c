#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <locale.h>

//������� �������� ���������� ����� �������

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
			printf("����� ��������!\n");
			break;
		default:
			printf("������ ������������ ����� �������!\n");
		}
	} while (sel != 0);
	_getch();
	return 0;
}

void massive() // ������� �������� � ������ �� ����� ������� ���������������� �� ��������� �����
{

	int i;
	printf("������� ������ �������: ");
	scanf("%d", &ArraySize);
	printf("\n");
	srand(time(NULL));
	AllElements = malloc(ArraySize * sizeof(int));

	printf("��������������� ������:\n");
	for (i = 0; i < ArraySize; i++)
	{
		AllElements[i] = rand() % 101;
		printf("%d ", AllElements[i]);
	}
	printf("\n");
}

/*
������� 1.
����������� �������������� ����������� ����������. �������� ���������� �������� ���������
���������������� � �� ���������������� ���������. �������� ������� ����������, �������
���������� ���������� ��������.
*/

void swap(int *AllElements, int *b) // ������� �����������
{
	int  t = *AllElements;
	*AllElements = *b;
	*b = t;
}

void print(int ArraySize, int* AllElements) // ������� ������ �������
{
	int i;
	for (i = 0; i < ArraySize; i++)
	{
		printf("%i ", AllElements[i]);
	}
	printf("\n");
}

void sort(int ArraySize, int* AllElements) // ������� ����������� ����������
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
	printf("\n������ ����� ����������� ����������:\n");
	print(ArraySize, AllElements);
	printf("\n");
	printf("������� ���������� �������� �����: %d\n", count1);
}

void sortopt(int ArraySize, int* AllElements, bool asc) // ���������������� ����������� ����������
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
	printf("\n������ ����� ���������������� ����������� ����������:\n");
	print(ArraySize, AllElements);
	printf("\n");
	printf("������� ���������� �������� ����� ���������������� ����������� ���������� �����: %d\n", count2);
}

// ������� 1.

void task1()
{
	printf("������� �1\n");
	printf("����������� �������������� ����������� ���������� � �.�.\n");
	
	int i;

	massive(AllElements, ArraySize);

	sort(ArraySize, AllElements);

	sortopt(ArraySize, AllElements, true);
}

/*
������� 2.
����������� ��������� ����������.
*/

void ShakerSort(int* AllElements, int ArraySize) // ������� ��������� ����������
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

	printf("\n������ ����� ��������� ����������:\n");
	print(ArraySize, AllElements);
	printf("\n");
	printf("������� ���������� �������� ����� ��������� ���������� �����: %d\n\n", count3);
}

// ������� 2.
void task2()
{
	printf("������� �2\n");
	printf("����������� ��������� ����������\n");

	massive(AllElements, ArraySize);

	ShakerSort(AllElements, ArraySize);

}

/*
������� 3.
����������� �������� �������� ������ � ���� �������, ������� ���������� ���������������
������. ������� ���������� ������ ���������� �������� ��� -1, ���� ������� �� ������.
*/

int task3()
{
	printf("������� �3\n");
	printf("����������� �������� �������� ������ � ���� �������\n");

	int Middle;
	int k;
	int cip;

	printf("������� ������ �������:");
	scanf("%d", &ArraySize);

	AllElements = (int*)malloc(ArraySize * sizeof(int));
	cip = 0;
	for (int j = 0; j < ArraySize; j++) {
		AllElements[j] = cip;
		cip++;
	}

	printf("������� �������� ��� ������:");
	scanf("%d", &SearchValue);

	printf("��������������� ������:\n");
	for (int i = 0; i < ArraySize; i++)
		printf("%d ", AllElements[i]);
	printf("\n");

	k = binarysearch(ArraySize, AllElements, SearchValue);
	if (k != -1)
	{
		printf("������:%d", k);
		printf("\n");
	}
	else
		printf("�������� �� �������");
	printf("\n");
	free(AllElements);

}

int binarysearch(int ArraySize, int AllElements[], int SearchValue) // ������� ��������� ������
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

/*������� 4.
���������� ���������� �������� ��� ������ �� ���������� � �������� ��� � ���������������
���������� ���������
*/
void task4()
{
	printf("\n������� �4\n");
	printf("���������� ���������� �������� ��� ������ �� ���������� � �������� ��� � ��������������� ���������� ���������\n");

	int i;

	massive(AllElements, ArraySize);

	sort(ArraySize, AllElements);

	sortopt(ArraySize, AllElements, true);
	
	ShakerSort(AllElements, ArraySize);

	int j = 0;
	int jmin;
	int count4 = 0;
	int count5 = 0;

	// ���������� ������� ������
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

	puts("������ ����� ���������� ������� ������");
	print(ArraySize, AllElements);
	printf("\n");
	printf("������� ���������� �������� ����� ���������� ������� ������ �����: %d\n\n", count4);

	// ���������� ���������
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
	printf("������� ���������� �������� ����� ���������� ��������� �����: %d\n\n", count5);
	printf("\n");
}

void menu()
{
	printf("������� ����� �������, ������� ������ ���������� � ������� Enter\n");
	printf("1 - ������� 1\n");
	printf("2 - ������� 2\n");
	printf("3 - ������� 3\n");
	printf("4 - ������� 4\n");
	printf("0 - Exit\n");
}