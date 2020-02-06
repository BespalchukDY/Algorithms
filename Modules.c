#include "Modules.h"

// Считываем из файла матрицу
int load(int W[N][N])
{
	FILE* file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Невозможно открыть файл");
		exit(1);
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			int a;
			fscanf(file, "%d", &a);
			if (a == 0)
				W[i][j] = MaxInt;
			else
				W[i][j] = a;
		}
	fclose(file);
	return 0;
}

void printMatrix(int W[N][N])
{
	printf("%s", "");

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%5d", (W[i][j] == MaxInt) ? 0 : W[i][j]);
		printf("\n");
	}
	
}

int task1()
{
	printf("Задание №1: \n");
	printf("Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран\n");

	int W[N][N];
	load(W);
	printMatrix(W);

	printf("\n");
	return 0;
}

// Обход в глубину

void DFS(struct Graph* graph, int vertex) {
	struct node* adjList = graph->adjLists[vertex];
	struct node* temp = adjList;

	graph->visited[vertex] = 1;
	printf("Посетили %d \n", vertex);

	while (temp != NULL) {
		int connectedVertex = temp->vertex;

		if (graph->visited[connectedVertex] == 0) {
			DFS(graph, connectedVertex);
		}
		temp = temp->next;
	}
}

void printGraph(struct Graph* graph)
{
	int v;
	for (v = 0; v < graph->numVertices; v++)
	{
		struct node* temp = graph->adjLists[v];
		printf("\n Список смежности вершин %d\n ", v);
		while (temp)
		{
			printf("%d -> ", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
}

int task2()
{
	printf("Задание №2: \n");
	printf("Написать рекурсивную функцию обхода графа в глубину\n");

	struct Graph* graph = createGraph(4);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 2);
	addEdge(graph, 2, 3);

	printGraph(graph);

	DFS(graph, 2);

	printf("\n");
	return 0;
}

// Обход в ширину

struct node* createNode(int v)
{
	struct node* newNode = malloc(sizeof(struct node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int vertices)
{
	struct Graph* graph = malloc(sizeof(struct Graph));
	graph->numVertices = vertices;

	graph->adjLists = malloc(vertices * sizeof(struct node*));
	graph->visited = malloc(vertices * sizeof(int));


	int i;
	for (i = 0; i < vertices; i++) {
		graph->adjLists[i] = NULL;
		graph->visited[i] = 0;
	}

	return graph;
}


struct queue* createQueue() {
	struct queue* q = malloc(sizeof(struct queue));
	q->front = -1;
	q->rear = -1;
	return q;
}


void bfs(struct Graph* graph, int startVertex) {
	struct queue* q = createQueue();

	graph->visited[startVertex] = 1;
	enqueue(q, startVertex);

	while (!isEmpty(q)) {
		printQueue(q);
		int currentVertex = dequeue(q);
		printf("Посетили %d\n", currentVertex);

		struct node* temp = graph->adjLists[currentVertex];

		while (temp) {
			int adjVertex = temp->vertex;
			if (graph->visited[adjVertex] == 0) {
				graph->visited[adjVertex] = 1;
				enqueue(q, adjVertex);
			}
			temp = temp->next;
		}
	}
}

void addEdge(struct Graph* graph, int src, int dest)
{
	
	struct node* newNode = createNode(dest);
	newNode->next = graph->adjLists[src];
	graph->adjLists[src] = newNode;

	
	newNode = createNode(src);
	newNode->next = graph->adjLists[dest];
	graph->adjLists[dest] = newNode;
}

int isEmpty(struct queue* q) {
	if (q->rear == -1)
		return 1;
	else
		return 0;
}
void enqueue(struct queue* q, int value) {
	if (q->rear == SIZE - 1)
		printf("\nОчередь заполнена!");
	else {
		if (q->front == -1)
			q->front = 0;
		q->rear++;
		q->items[q->rear] = value;
	}
}
int dequeue(struct queue* q) {
	int item;
	if (isEmpty(q)) {
		printf("Очередь пуста ");
		item = -1;
	}
	else {
		item = q->items[q->front];
		q->front++;
		if (q->front > q->rear) {
			printf("Сброс очереди ");
			q->front = q->rear = -1;
		}
	}
	return item;
}
void printQueue(struct queue* q) {
	int i = q->front;
	if (isEmpty(q)) {
		printf("Очередь пуста");
	}
	else {
		printf("\nОчередь содержит \n");
		for (i = q->front; i < q->rear + 1; i++) {
			printf("%d ", q->items[i]);
		}
	}
}

int task3()
{
	printf("Задание №3: \n");
	printf("Написать функцию обхода графа в ширину\n");

	struct Graph* graph = createGraph(6);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 4);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 4);
	addEdge(graph, 3, 4);

	bfs(graph, 0);

	printf("\n");
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