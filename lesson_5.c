#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <locale.h>

#define T char

//������� �������� ���������� ����� �������

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
		printf("������ ��������� ������\n");
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
			printf("����� ��������!\n");
			break;
		default:
			printf("������ ������������ ����� �������!\n");
		}
	} while (sel != 0);
	_getch();
	return 0;
}

/*
������� 1.
����������� ������� �� ���������� � �������� ������� ��������� � �������������� �����
*/

int task1()
{
	printf("������� �1\n");
	printf("����������� ������� �� ���������� � �������� ������� ��������� � �������������� �����\n");
	
	Stack s;
	s.size = 0;
	s.head = NULL;
	unsigned int a;

	printf("������� ���������� �����: ");
	scanf("%d", &a);
	printf("%s ", "� �������� �������:");
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
������� 2.
�������� � ��������� ����������� ����� �� ������ ������������ ������ �������� �� ��������� ������. 
���� ������ �� ����������, �� ��������� ��������������� ���������. 
������������ ������� ��������, ����� ������ �� ����� ���������� (����������� �������� ���������� ������).
*/

void task2()
{
	printf("������� �2\n");
	printf("�������� � ��������� ����������� ����� �� ������ ������������ ������ �������� �� ��������� ������\n");

	printf("������ ��� ���������: ������ 32 - 46\n");

}

/*
������� 3.
�������� ���������, ������� ����������, �������� �� ��������� ���������
������������������ ����������. ������� ���������� ��������� ���������: (), ([])(), {}(),
([{}]), ������������ � )(, ())({), (, ])}), ([(]) ��� ������ [, (, {.
��������: (2+(2*2)) ��� [2/{5*(4+7)}].
*/

void task3()
{
	printf("������� �3\n");
	printf("�������� ���������, ������� ����������, �������� �� ��������� ��������� ������������������ ����������\n");

	char s[99];

	printf("������� ������������������: ");
	scanf("%s", s);

	puts(is_balance(s) ? "���������� ������������������" : "������������ ������������������");
}

void menu()
{
	printf("������� ����� �������, ������� ������ ���������� � ������� Enter\n");
	printf("1 - ������� 1\n");
	printf("2 - ������� 2\n");
	printf("3 - ������� 3\n");
	printf("0 - Exit\n");
}