#include <stdio.h>
#include<string.h>
#include <locale.h>

#define N 4
#define M 4

//Задание выполнил Беспальчук Денис Юрьевич

int i, j, m, n, c[20][20];
char x[20], y[20], b[20][20];

int ARR[8][8];
const int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int s;

void task1();
void Print1(int n, int m, int a[N][M]);

void task2();
void print2(int i, int j);
void lcs();

int task3();
void rek(int x, int y, int step);

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
*Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и
нахождение количество маршрутов.
Например, карта:
3 3
1 1 1
0 1 0
0 1 0
*/

void task1()
{
	printf("Задание №1\n");
	printf("Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количества маршрутов\n");

	int A[N][M];
	int Map[3][3] = {
		{1, 1, 1},
		{0, 1, 0},
		{0, 1, 0}
					};
	int i, j;

	for (j = 0; j < M; j++)
		A[0][j] = 1;

	for (i = 1; i < N; i++)
	{
		A[i][0] = 1;
		A[1][0] = Map[1][0];
		A[2][0] = Map[2][0];
		A[1][2] = Map[1][2];
		A[2][2] = Map[2][2];
		for (j = 1; j < M; j++)
		{
			if (A[i][j] != 0)
			{
				A[i][j] = A[i][j - 1] + A[i - 1][j];
			}
			else A[i][j] = 0;
		}
	}
	Print1(N, M, A);
	printf("\n");
}

void Print1(int n, int m, int a[N][M])
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
}

/*
Задание 2.
Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.
*/

void task2()
{
	printf("Задание №2\n");
	printf("Решить задачу о нахождении длины максимальной последовательности с помощью матрицы\n");
	
	printf("Enter 1st sequence:");
	scanf("%s", x);
	printf("Enter 2nd sequence:");
	scanf("%s", y);
	printf("\nThe Longest Common Subsequence is ");
	lcs();
	print2(m, n);
	printf("\n\n");
}

void print2(int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 'c')
	{
		print2(i - 1, j - 1);
		printf("%c", x[i - 1]);
	}
	else if (b[i][j] == 'u')
		print2(i - 1, j);
	else
		print2(i, j - 1);
}

void lcs()
{
	m = strlen(x);
	n = strlen(y);
	for (i = 0; i <= m; i++)
		c[i][0] = 0;
	for (i = 0; i <= n; i++)
		c[0][i] = 0;

	//c, u и l обозначают поперечное, восходящее и нисходящее направления соответственно(cross upper lower)
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 'c';
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 'u';
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = 'l';
			}
		}
}

/*
Задание 3.
***Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по
одному разу. Здесь алгоритм решения такой же как и в задаче о 8 ферзях. Разница только в проверке
положения коня
*/

int task3()
{
	printf("Задание №3\n");
	printf("Требуется обойти конём шахматную доску размером 8 x 8, пройдя через все поля доски по одному разу\n");

	int x, y;
	s = 2;

	for (x = 0; x < 8; x++)
	{
		for (y = 0; y < 8; y++)
		{
			ARR[x][y] = 0;
		}
	}
	
	ARR[0][0] = 1;

	rek(0, 0, 1);

	for (x = 0; x < 8; x++)
	{
		for (y = 0; y < 8; y++)
		{
			printf("%4d ", ARR[x][y]);
		}
		printf("\n");
	}
}

void rek(int x, int y, int step)
{
	ARR[x][y] = step;
	int i;

	for (i = 0; i < 8; i++)
	{
		int x1 = x + dx[i];
		int y1 = y + dy[i];

		if ((x1 >= 0) && (y1 >= 0) && (x1 < 8) && (y1 < 8) && (ARR[x1][y1] == 0))
		{
			rek(x1, y1, step + 1);
		}
	}
}

void menu()
{
	printf("Введите номер задания, которое хотите посмотреть и клавишу Enter\n");
	printf("1 - Задание 1\n");
	printf("2 - Задание 2\n");
	printf("3 - Задание 3\n");
	printf("0 - Exit\n");
}