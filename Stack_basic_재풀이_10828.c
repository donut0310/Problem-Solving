//#include<stdio.h>
//#include<string.h>
//#include<stdio.h>
//
////노드 껍데기
//typedef struct Node {
//	struct Node* next;
//	int data;
//}Node;
//
////스택 껍데기
//typedef struct listStack {
//	Node* peek;
//	int size;
//}listStack;
//
////노드 생성
//Node* createNode(int data)
//{
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->next = NULL;
//	newNode->data = data;
//	return newNode;
//}
//
////스택 생성
//void createStack(listStack** Stack)
//{
//	*Stack = (listStack*)malloc(sizeof(listStack));
//	(*Stack)->peek = NULL;
//	(*Stack)->size = 0;
//}
//
////노드 삭제
//void deleteNode(Node* remove)
//{
//	free(remove);
//}
//
////push
//void push(listStack* Stack, Node* newNode)
//{
//	//스택이 비어있을때
//	if (Stack->size == 0)
//	{
//		Stack->peek = newNode;
//	}
//	//스택이 비어있지 않을때
//	else
//	{
//		newNode->next = Stack->peek;
//		Stack->peek = newNode;
//	}
//	Stack->size++;
//}
////pop
//void pop(listStack* Stack)
//{
//	//스택이 비어있을때
//	if (Stack->peek == NULL)printf("-1\n");
//	
//	//스택이 비어있지 않을때
//	else
//	{
//		Node* temp = NULL;
//		temp = Stack->peek;
//		Stack->peek = Stack->peek->next;
//		printf("%d\n", temp->data);
//		deleteNode(temp);
//		Stack->size--;
//	}
//}
////size
//void size(listStack* Stack)
//{
//	printf("%d\n", Stack->size);
//}
////empty
//void empty(listStack* Stack)
//{
//	//스택이 비어있을때
//	if (Stack->size == 0)
//	{
//		printf("1\n");
//	}
//	//스택이 비어있지 않을때
//	else
//	{
//		printf("0\n");
//	}
//}
////top
//void top(listStack* Stack)
//{
//	//스택이 비어있을때
//	if (Stack->size == 0)
//	{
//		printf("-1\n");
//	}
//	//스택이 비어있지 않을때
//	else
//	{
//		printf("%d\n", Stack->peek->data);
//	}
//}
//
//int main()
//{
//	char tmp[10], *input_func;
//	int n;
//	int len;
//	int num;
//	scanf("%d", &n);
//
//	listStack* mainStack=NULL;
//	createStack(&mainStack);
//
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%s", tmp);
//		len = strlen(tmp);
//		input_func = (char*)malloc(sizeof(char)*(len+1));
//		strcpy(input_func, tmp);
//
//		if (strcmp(input_func, "push") == 0)
//		{
//			scanf("%d", &num);
//			Node* newNode = createNode(num);
//			push(mainStack, newNode);
//		}
//		else if (strcmp(input_func, "pop") == 0)
//		{
//			pop(mainStack);
//		}
//		else if (strcmp(input_func, "size") == 0)
//		{
//			size(mainStack);
//		}
//		else if (strcmp(input_func, "empty") == 0)
//		{
//			empty(mainStack);
//		}
//		else if (strcmp(input_func, "top") == 0)
//		{
//			top(mainStack);
//		}
//	}
//
//}