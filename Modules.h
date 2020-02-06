#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define N 5

#define filename "Lesson_7.txt"
#define MaxInt 20000000

#define SIZE 40

struct queue {
    int items[SIZE];
    int front;
    int rear;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);

int isEmpty(struct queue* q);
void printQueue(struct queue* q);

struct node
{
    int vertex;
    struct node* next;
};

struct node* createNode(int);

struct node* createNode(int v);

struct Graph
{
    int numVertices;
    struct node** adjLists;
    int* visited;
};

struct Graph* createGraph(int vertices);
struct Graph* createGraph(int);

void addEdge(struct Graph*, int, int);
void printGraph(struct Graph*);
void DFS(struct Graph*, int);

void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
void bfs(struct Graph* graph, int startVertex);

void printMatrix(int W[N][N]);
int load(int W[N][N]);


int task1();

int task2();

int task3();

void menu();




