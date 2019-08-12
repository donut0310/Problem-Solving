#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//��� ������
typedef struct Node {
	struct Node* next;
	struct Node* prev;
	int data;
}Node;

//��� ����
Node* createNode(int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}

//ť ������
typedef struct listQueue {
	Node* front;
	Node* rear;
	int size;
}listQueue;

//ť ����
void createQueue(listQueue** Queue)
{
	*Queue = (listQueue*)malloc(sizeof(listQueue));
	(*Queue)->front = NULL;
	(*Queue)->rear = NULL;
	(*Queue)->size = 0;
}

//push
void push(listQueue* Queue, int data)
{
	Node* newNode = createNode(data);

	if (Queue->size == 0)
	{
		Queue->front = newNode;
		Queue->rear = newNode;
	}
	else
	{
		Queue->rear->next = newNode;
		Queue->rear = Queue->rear->next;
		Queue->rear->next = Queue->front;
	}
	Queue->size++;
}

//pop
Node* pop(listQueue* mainQueue)
{
	Node* temp = mainQueue->front; //front �� �̸� �Űܳ���
	if (mainQueue->size == 1)
	{
		mainQueue->front = NULL;
		mainQueue->rear = NULL;
		mainQueue->size--;
	}
	else if (mainQueue->size > 1)
	{
		mainQueue->rear->next = mainQueue->front->next;
		mainQueue->front = mainQueue->front->next;
		mainQueue->size--;
	}
	return temp;
}

//���
void print(listQueue* subQueue)
{
	Node* horse = subQueue->front;

	printf("<");
	for (int i = 0; i < subQueue->size-1; i++)
	{
		printf("%d, ", horse->data);
		horse = horse->next;
	}
	printf("%d>",horse->data);
}

//�����۽� ����
void func(listQueue* mainQueue, listQueue* subQueue, int k)
{
	// k��° �����Ͱ� ������ ������ mainQueue�� front �����ʹ� rear�� ��ġ�� �������ְ� front�����ʹ� ��ĭ�� �̷��
	// k��° �����Ͱ� ������ subQueue�� ����
	
	int cnt = 1;

	while (mainQueue->size > 0)
	{
		
	
		// k��° �����͸� ������ mianQueue�� front ���� pop �� �� subQueue�� �־��ش�
		if (cnt == k)
		{
			Node* popNode = pop(mainQueue);
			push(subQueue, popNode->data);
			cnt = 1;
		}

		//�ƴϸ� mainQueue�� front ���� rear��ġ�� ����
		else
		{
			mainQueue->rear = mainQueue->rear->next;
			mainQueue->front = mainQueue->front->next;
			cnt++;
		}
	}
	print(subQueue);
}

int main()
{
	int num, k;
	scanf("%d %d", &num, &k);

	listQueue* mainQueue = NULL;
	createQueue(&mainQueue);

	for (int i = 1; i <= num; i++)
	{
		push(mainQueue, i);
	}

	listQueue* subQueue = NULL;
	createQueue(&subQueue);

	func(mainQueue, subQueue, k);

	

}