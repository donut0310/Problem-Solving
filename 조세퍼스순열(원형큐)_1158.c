#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//노드 껍데기
typedef struct Node {
	struct Node* next;
	struct Node* prev;
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
	Node* temp = mainQueue->front; //front 값 미리 옮겨놓기
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

//출력
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

//조세퍼스 순열
void func(listQueue* mainQueue, listQueue* subQueue, int k)
{
	// k번째 데이터가 나오기 전까지 mainQueue의 front 데이터는 rear의 위치로 변경해주고 front데이터는 한칸을 미룬다
	// k번째 데이터가 나오면 subQueue에 저장
	
	int cnt = 1;

	while (mainQueue->size > 0)
	{
		
	
		// k번째 데이터를 만나면 mianQueue의 front 값을 pop 한 후 subQueue에 넣어준다
		if (cnt == k)
		{
			Node* popNode = pop(mainQueue);
			push(subQueue, popNode->data);
			cnt = 1;
		}

		//아니면 mainQueue의 front 값을 rear위치로 변경
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