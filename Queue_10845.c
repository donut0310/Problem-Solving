#include<stdio.h>
#include<stdlib.h>

//노드 껍데기
typedef struct Node {
	struct Node* next;
	int data;
}Node;

//노드 생성
Node* createNode(int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}

//큐 껍데기
typedef struct listQueue {
	Node* front;
	Node* rear;
	int size;
}listQueue;

//큐 생성
void createQueue(listQueue** Queue)
{
	*Queue = (listQueue*)malloc(sizeof(listQueue));
	(*Queue)->front = NULL;
	(*Queue)->rear = NULL;
	(*Queue)->size = 0;
}
//enque
void push(listQueue* Queue, int data)
{
	Node* newNode = createNode(data);
	//큐가 비어있을때
	if (Queue->size == 0)
	{
		Queue->front = newNode;
		Queue->rear = newNode;
	}
	//큐가 비어있지 않을때 front는 가만히, rear만 변경
	else
	{
		Queue->rear->next = newNode;
		Queue->rear = newNode;
	}
	Queue->size++;
}
//deque front 제거
void pop(listQueue* Queue)
{
	Node* temp = Queue->front;

	//큐가 비어있을때
	if (Queue->size == 0)
	{
		printf("-1\n");
		return;
	}
	//큐가 한개 일때
	else if (Queue->size == 1)
	{
		Queue->front = NULL;
		Queue->rear = NULL;
	}
	//큐가 한개 이상일때
	else
	{
		Queue->front = Queue->front->next;
	}
	Queue->size--;
	printf("%d\n", temp->data);
	free(temp);
	
}

//size
void size(listQueue* Queue)
{
	printf("%d\n", Queue->size);
}

//empty
void empty(listQueue* Queue)
{
	if (Queue ->size ==0 )printf("1\n");
	else
	{
		printf("0\n");
	}
}

//front
void front(listQueue* Queue)
{
	if (Queue ->size == 0)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", Queue->front->data);
	}
}

//back
void back(listQueue* Queue)
{
	if (Queue->size == 0)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", Queue->rear->data);
	}
}

int main()
{
	int n;
	int input_data;
	scanf("%d", &n);

	char tmp[10], *func;
	listQueue* mainQueue = NULL;
	createQueue(&mainQueue);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", tmp);
		int len = strlen(tmp);

		func = (char*)malloc((len+1)*sizeof(char));
		strcpy(func, tmp);

		if (strcmp(func, "push") == 0)
		{
			scanf("%d", &input_data);
			push(mainQueue,input_data);
		}
		else if (strcmp(func, "pop") == 0)
		{
			pop(mainQueue);
		}
		else if (strcmp(func, "size") == 0)
		{
			size(mainQueue);
		}
		else if (strcmp(func, "empty") == 0)
		{
			empty(mainQueue);
		}
		else if (strcmp(func, "front") == 0)
		{
			front(mainQueue);
		}
		else if (strcmp(func, "back") == 0)
		{
			back(mainQueue);
		}
	}
}