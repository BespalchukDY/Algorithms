#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <locale.h>

#define T char

//Задание выполнил Беспальчук Денис Юрьевич

int task1();

void task2();

void task3();

void menu();


typedef struct Node {
	T data;
	struct Node* next;
} Node;

typedef struct {
	Node* head;
	int size;
} Stack;

int push(Stack* st, T val) {
	Node* temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL)
	{
		printf("Ошибка выделения памяти\n");
		return 0;
	}

	temp->data = val;
	temp->next = st->head;

	st->head = temp;
	st->size++;
	return 1;
}

T pop(Stack* st) {
	if (st->size == 0) {
		return -1;
	}
	Node* temp = st->head;
	T result = st->head->data;

	st->head = st->head->next;
	st->size--;
	free(temp);
	return result;
}

int is_balance(const char* s) {
	int   i, ds[3];
	const char* p;
	const char beg[] = "({[";
	const char end[] = ")}]";

	memset(ds, 0, sizeof(ds));
	for (; *s; ++s) {
		if ((p = strchr(beg, *s)) != NULL)
			++ds[p - beg];
		else if ((p = strchr(end, *s)) != NULL) {
			if (--ds[p - end] < 0)
				return 0;
		}
	}

	for (i = 0; i < 3; ++i) {
		if (ds[i] > 0)
			return 0;
	}
	return 1;
}

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
Реализовать перевод из десятичной в двоичную систему счисления с использованием стека
*/

int task1()
{
	printf("Задание №1\n");
	printf("Реализовать перевод из десятичной в двоичную систему счисления с использованием стека\n");
	
	Stack s;
	s.size = 0;
	s.head = NULL;
	unsigned int a;

	printf("Введите десятичное число: ");
	scanf("%d", &a);
	printf("%s ", "В двоичной системе:");
	for (; a != 0; a /= 2)
	{
		if (a % 2)
			push(&s, '1');
		else
			push(&s, '0');
	}

	while (s.size > 0) {
		printf("%c ", pop(&s));
	}
	printf("\n\n");

}

/*
Задание 2.
Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти. 
Если память не выделяется, то выводится соответствующее сообщение. 
Постарайтесь создать ситуацию, когда память не будет выделяться (добавлением большого количества данных).
*/

void task2()
{
	printf("Задание №2\n");
	printf("Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти\n");

	printf("Смотри код программы: строки 32 - 46\n");

}

/*
Задание 3.
Написать программу, которая определяет, является ли введенная скобочная
последовательность правильной. Примеры правильных скобочных выражений: (), ([])(), {}(),
([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [, (, {.
Например: (2+(2*2)) или [2/{5*(4+7)}].
*/

void task3()
{
	printf("Задание №3\n");
	printf("Написать программу, которая определяет, является ли введенная скобочная последовательность правильной\n");

	char s[99];

	printf("Введите последовательность: ");
	scanf("%s", s);

	puts(is_balance(s) ? "Правильная последовательность" : "Неправильная последовательность");
}

void menu()
{
	printf("Введите номер задания, которое хотите посмотреть и клавишу Enter\n");
	printf("1 - Задание 1\n");
	printf("2 - Задание 2\n");
	printf("3 - Задание 3\n");
	printf("0 - Exit\n");
}