#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct listNode {
	struct listNode* next;
	int data;
}Node;

typedef struct listStack {
	Node* peek;
	int size;
}listStack;

//노드 생성
Node* createNode(int num)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = num;
	newNode->next = NULL;
	return newNode;
}

//스택 생성
void createStack(listStack** Stack)
{
	(*Stack) = (listStack*)malloc(sizeof(listStack));
	(*Stack)->peek = NULL;
	(*Stack)->size = 0;
}

//노드 삭제
void deleteNode(Node* removeNode)
{
	free(removeNode);
}
//push함수
void push(listStack* Stack,Node* newNode)
{
	//스택이 비어있을때
	if (Stack->size == 0)
	{
		Stack->peek = newNode;
	}
	//스택이 비어있지 않을때
	else
	{
		newNode->next = Stack->peek;
		Stack->peek = newNode;
	}
	Stack->size++;
}

//pop함수 정수가 없으면 -1 출력
void pop(listStack* Stack)
{
	Node* temp=NULL;
	if (Stack->peek== NULL)printf("-1\n");
	else
	{
		temp = Stack->peek;
		Stack->peek = Stack->peek->next;
		printf("%d\n", temp->data);
		Stack -> size--;
		
		deleteNode(temp);
	}
	
}

//스택에 들어있는 정수의 개수 출력
void size(listStack* Stack)
{
	
	printf("%d\n", Stack->size);

}

//스택이 비어있으면 1, 아니면 0을 출력
void empty(listStack* Stack)
{
	if (Stack->peek== NULL)printf("1\n");
	else
	{
		printf("0\n");
	}
}

//스택의 가장 위에있는 정수 출력 정수가 없으면 -1출력
void top(listStack* Stack)
{
	if (Stack->peek == NULL)printf("-1\n");
	else
	{
		printf("%d\n", Stack->peek->data);
	}
}

int main()
{
	int max;
	int input;
	char fun[100],*input_fun;

	listStack* mainStack=NULL;
	scanf("%d", &max); 

	createStack(&mainStack);
	for (int i = 0; i < max; i++)
	{
		scanf("%s", fun);
		input_fun = (char*)malloc((strlen(fun) + 1) * sizeof(char));
		strcpy(input_fun, fun);

		if (strcmp(input_fun, "push") == 0)
		{
			scanf("%d", &input);
			Node* newNode = createNode(input);
			push(mainStack,newNode);
		}
		else if (strcmp(input_fun, "pop") == 0)
		{
			pop(mainStack);
		}
		else if (strcmp(input_fun, "size") == 0)
		{
			size(mainStack);
		}
		else if (strcmp(input_fun, "empty") == 0)
		{
			empty(mainStack);
		}
		else if (strcmp(input_fun, "top") == 0)
		{
			top(mainStack);
		}
	
	
	}
}