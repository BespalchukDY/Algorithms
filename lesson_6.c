#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

#define CMP_LT(a, b) ((a) < (b))
#define CMP_GT(a, b) ((a) > (b))

//������� �������� ���������� ����� �������

typedef int T;
typedef struct Node {
	T data;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;

void printTree(Node *root) {
	if (root)
	{
		printf("%d", root->data);
		if (root->left || root->right)
		{
			printf("(");

			if (root->left)
				printTree(root->left);
			else
				printf("NULL");
			printf(",");

			if (root->right)
				printTree(root->right);
			else
				printf("NULL");
			printf(")");
		}
	}
}

Node* getFreeNode(T value, Node *parent) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}

Node* getNodeByValue(Node* root, T value) {
	while (root) {
		if (CMP_GT(root->data, value)) {
			root = root->left;
			continue;
		}
		else if (CMP_LT(root->data, value)) {
			root = root->right;
			continue;
		}
		else
		{
			return root;
		}
	}
	return NULL;
}

void insert(Node **head, int value) {
	Node *tmp = NULL;
	if (*head == NULL)
	{
		*head = getFreeNode(value, NULL);
		return;
	}

	tmp = *head;
	while (tmp)
	{
		if (value> tmp->data)
		{
			if (tmp->right)
			{
				tmp = tmp->right;
				continue;
			}
			else
			{
				tmp->right = getFreeNode(value, tmp);
				return;
			}
		}
		else if (value< tmp->data)
		{
			if (tmp->left)
			{
				tmp = tmp->left;
				continue;
			}
			else
			{
				tmp->left = getFreeNode(value, tmp);
				return;
			}
		}
		else
		{
			exit(2);
		}
	}
}

void preOrderTravers(Node* root) {
	if (root) {
		printf("%d ", root->data);
		preOrderTravers(root->left);
		preOrderTravers(root->right);
	}
}

void inOrderTravers(Node* root) {
	if (root) {
		inOrderTravers(root->left);
		printf("%d ", root->data);
		inOrderTravers(root->right);
	}
}

void postOrderTravers(Node* root) {
	if (root) {
		postOrderTravers(root->left);
		postOrderTravers(root->right);
		printf("%d ", root->data);
	}
}


int task1();
int hash(char* S);

int task2();

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
����������� ���������� ���-�������. �� ���� ������� �������� ������, �� ������ ����� ����� ��������.
*/

int task1()
{
	printf("������� �1\n");
	printf("����������� ���������� ���-�������. �� ���� ������� �������� ������, �� ������ ����� ����� ��������.\n");

	char S[] = "Hello!";
	puts(S);

	hash(S);

	printf("\n\n");
	return 0;
}

int hash(char *S)
{
	int i, r = 0;
	while (*S)
	{
		r += (int)(*S);
		S++;
	}
	printf("%X", S);
	return r;
}

/*
������� 2.
���������� ���������, ����������� �������� ������ ������.
�) �������� � ���� ����� ������ ���������� ���������;
�) ����������� ����� � �������� ������ ������;

*/

int task2()
{
	printf("������� �2\n");
	printf("���������� ���������, ����������� �������� ������ ������\n");

	Node *Tree = NULL;

	FILE* file = fopen("D:\\data.txt", "r");
	
	if (file == NULL)
	{
		puts("���������� ������� ����!");
		exit(1);
	}
	
	int count;
	fscanf(file, "%d", &count);
	
	int i;
	for (i = 0; i < count; i++)
	{
		int value;
		fscanf(file, "%d", &value);
		insert(&Tree, value);
	}
	fclose(file);

	printTree(Tree);

	printf("\nPreOrderTravels: ");
	preOrderTravers(Tree);

	printf("\ninOrderTravels: ");
	inOrderTravers(Tree);

	printf("\npostOrderTravels: ");
	postOrderTravers(Tree);
	printf("\n");

	printf("��������� 6 �������� %d", getNodeByValue(Tree, 6)->parent->data);

	printf("\n\n"); 
	return 0;
}

/*
������� 3.
����������� ���� ������ ��������� �� ����� �����, ��������, ���������� �����, � ������� ������������ ��� ������, ���������� �� ������.
�������� ������ � �������� ������ ������. ���������� ����� �� ������-������ ���� ���� ������ (�������, ���)

*/


void menu()
{
	printf("������� ����� �������, ������� ������ ���������� � ������� Enter\n");
	printf("1 - ������� 1\n");
	printf("2 - ������� 2\n");
	printf("0 - Exit\n");
}