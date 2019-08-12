//#include<stdio.h>
//#include<stdlib.h>
//
////노드 껍데기
//typedef struct Node {
//	struct Node* next;
//	struct Node* prev;
//	int data;
//}Node;
//
////노드 생성
//Node* createNode(int data)
//{
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->next = NULL;
//	newNode->prev = NULL;
//	newNode->data = data;
//	return newNode;
//}
//
////큐 껍데기
//typedef struct listQueue {
//	Node* front;
//	Node* rear;
//	int size;
//}listQueue;
//
////큐 생성
//void createQueue(listQueue** Queue)
//{
//	*Queue = (listQueue*)malloc(sizeof(listQueue));
//	(*Queue)->front = NULL;
//	(*Queue)->rear = NULL;
//	(*Queue)->size = 0;
//}
////push_front
//void push_front(listQueue* Queue, int data)
//{
//	Node* newNode = createNode(data);
//	//큐가 비어있을때
//	if (Queue->size == 0)
//	{
//		Queue->front = newNode;
//		Queue->rear = newNode;
//	}
//	//큐가 비어있지 않을때 rear 가만히, front 변경
//	else
//	{
//		Queue->front->prev = newNode;
//		newNode->next = Queue->front;
//		Queue->front = newNode;
//
//	}
//	Queue->size++;
//}
//
////push_back
//void push_back(listQueue* Queue, int data)
//{
//	Node* newNode = createNode(data);
//	//큐가 비어있을때
//	if (Queue->size == 0)
//	{
//		Queue->front = newNode;
//		Queue->rear = newNode;
//	}
//	//큐가 비어있지 않을때 front 가만히, rear 변경
//	else
//	{
//		Queue->rear->next = newNode;
//		newNode->prev = Queue->rear;
//		Queue->rear = newNode;
//	}
//	Queue->size++;
//}
//
////pop_front
//void pop_front(listQueue* Queue)
//{
//	Node* temp = Queue->front;
//	//큐가 비어있을때
//	if (Queue->size == 0)
//	{
//		printf("-1\n");
//		return;
//	}
//	else if (Queue->size == 1)
//	{
//		Queue->front = NULL;
//		Queue->rear = NULL;
//	}
//	else
//	{
//		Queue->front = Queue->front->next;
//		Queue->front->prev = NULL;
//	}
//	printf("%d\n", temp->data);
//	Queue->size--;
//	free(temp);
//
//}
//
////pop_back
//void pop_back(listQueue* Queue)
//{
//	Node* temp = Queue->rear;
//	//큐가 비어있을때
//	if (Queue->size == 0)
//	{
//		printf("-1\n");
//		return;
//	}
//	else if (Queue->size == 1)
//	{
//		Queue->front = NULL;
//		Queue->rear = NULL;
//	}
//	else
//	{
//		Queue->rear = Queue->rear->prev;
//		Queue->rear->next = NULL;
//	}
//	printf("%d\n", temp->data);
//	Queue->size--;
//	free(temp);
//
//}
//
////size
//void size(listQueue* Queue)
//{
//	printf("%d\n", Queue->size);
//}
////empty
//void empty(listQueue* Queue)
//{
//	if (Queue->size == 0)
//	{
//		printf("1\n");
//	}
//	else
//	{
//		printf("0\n");
//	}
//}
////print_front
//void front(listQueue* Queue)
//{
//	if (Queue->size == 0)
//	{
//		printf("-1\n");
//	}
//	else
//	{
//		printf("%d\n", Queue->front->data);
//	}
//}
////print_back
//void back(listQueue* Queue)
//{
//	if (Queue->size == 0)
//	{
//		printf("-1\n");
//	}
//	else
//	{
//		printf("%d\n", Queue->rear->data);
//	}
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	char tmp[20], *func;
//	listQueue *mainQueue = NULL;
//	createQueue(&mainQueue);
//	for (int i = 0; i < n; i++)
//	{
//
//		scanf("%s", tmp);
//		int len = strlen(tmp);
//		func = (char*)malloc((len + 1) * sizeof(char));
//		strcpy(func, tmp);
//
//		if (strcmp(func, "push_front") == 0)
//		{
//			int input_data;
//			scanf("%d", &input_data);
//			push_front(mainQueue, input_data);
//		}
//		else if (strcmp(func, "push_back") == 0)
//		{
//			int input_data;
//			scanf("%d", &input_data);
//			push_back(mainQueue, input_data);
//		}
//		else if (strcmp(func, "pop_front") == 0)
//		{
//			pop_front(mainQueue);
//		}
//		else if (strcmp(func, "pop_back") == 0)
//		{
//			pop_back(mainQueue);
//		}
//		else if (strcmp(func, "size") == 0)
//		{
//			size(mainQueue);
//		}
//		else if (strcmp(func, "empty") == 0)
//		{
//			empty(mainQueue);
//		}
//		else if (strcmp(func, "front") == 0)
//		{
//			front(mainQueue);
//		}
//		else if (strcmp(func, "back") == 0)
//		{
//			back(mainQueue);
//		}
//	}
//}