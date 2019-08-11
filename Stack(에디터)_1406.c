#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//��� ������
typedef struct Node {
	struct Node* next;

	char data;
}Node;

//��� ����
Node* createNode(char data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}

//���� ������
typedef struct listStack {
	Node* cursor;
	int size;
}listStack;

//���� ����
void createStack(listStack** Stack)
{
	*Stack = (listStack*)malloc(sizeof(listStack));
	(*Stack)->cursor = NULL;
	(*Stack)->size = 0;
}

//push -> �Է� ���ڿ� ���ÿ� ����
void push(listStack* Stack, char data)
{
	Node* newNode = createNode(data);

	//������ ���������
	if (Stack->size == 0)
	{
		Node* newcursor = (Node*)malloc(sizeof(Node));
		newcursor->data = NULL;
		newcursor->next = NULL;
		Stack->cursor = newcursor;
		Stack->cursor->next = newNode;
		Stack->size++;
	}
	else
	{
		newNode->next = Stack->cursor->next;
		Stack->cursor->next = newNode;
	}
	Stack->size++;
}


//push_left
void push_left(listStack* mainStack_A, listStack* mainStack_B)
{
	if (mainStack_A->cursor->next == NULL)
	{
		return;
	}
	else
	{
		Node* temp = mainStack_A->cursor->next;
		//B���ÿ� A������ Ŀ�������͸� ��������
		//A������ Ŀ�������ʹ� ��ġ�� ������ ����
		push(mainStack_B, mainStack_A->cursor->next->data);

		mainStack_A->cursor->next = mainStack_A->cursor->next->next;
		mainStack_A->size--;
		free(temp);

	}
}
// a b cursor
// a cursor b
//push_right
void push_right(listStack* mainStack_A, listStack* mainStack_B)
{
	//null���� ���� cursor��尡 �ֱ⿡ size=1
	if (mainStack_B->size == 1)
	{
		return;
	}
	else
	{
		Node* temp = mainStack_B->cursor->next;
		//A���ÿ� B������ Ŀ�������͸� ��������
		//B������ Ŀ�������ʹ� ��ġ�� ������ ����

		push(mainStack_A, mainStack_B->cursor->next->data);
		mainStack_B->cursor->next = mainStack_B->cursor->next->next;
		mainStack_B->size--;
		free(temp);
	}
}

//pop_left
void pop_left(listStack* mainStack_A)
{
	if (mainStack_A->cursor->next == NULL)
		return;
	else
	{
		Node* temp = mainStack_A->cursor->next;
		mainStack_A->cursor->next = mainStack_A->cursor->next->next;
		free(temp);
	}
	mainStack_A->size--;
}


//add_left
void add_left(listStack* mainStack_A, char add_data)
{
	Node* addNode = createNode(add_data);
	//Ŀ���� �Ǿտ� ��ġ�Ҷ�
	if (mainStack_A->cursor->next == NULL)
	{
		mainStack_A->cursor->next = addNode;
	}
	//Ŀ���տ� ��尡 �����Ҷ�
	else
	{
		addNode->next = mainStack_A->cursor->next;
		mainStack_A->cursor->next = addNode;
	}
	mainStack_A->size++;
}


int main()
{
	char str[100001];
	char input;
	char add_data;
	int num;
	listStack* mainStack_A = NULL;
	listStack* mainStack_B = NULL;
	createStack(&mainStack_A);
	createStack(&mainStack_B);

	scanf("%s", str);
	int len_str = strlen(str);
	//���ÿ� �Է� ���ڿ� ����
	for (int i = 0; i < len_str; i++)
	{
		push(mainStack_A, str[i]);
	}






	//��ɾ� Ƚ�� �Է�
	scanf("%d", &num);


	for (int i = 0; i < num; i++)
	{
		getchar();
		//input --> ��ɾ�
		scanf("%c", &input);

		if (input == 'L')
		{
			push_left(mainStack_A, mainStack_B);
		}
		else if (input == 'D')
		{
			push_right(mainStack_A, mainStack_B);
		}
		else if (input == 'B')
		{
			pop_left(mainStack_A);
		}
		else if (input == 'P')
		{
			getchar();
			scanf("%c", &add_data);
			add_left(mainStack_A, add_data);
		}
	}

	//
	//mainStack_A �Ųٷ� �����ؼ� subStack�� ����ѵڿ�
	//mainStack_B�� ���� ������ ���� ���

		//mainStack_A�� ���ڰ� ��������!
	if (mainStack_A->size > 0)
	{
		if (mainStack_A->cursor->next != NULL)
		{
			listStack* subStack_A = NULL;
			createStack(&subStack_A);

			Node* horse = mainStack_A->cursor->next;
			while (horse != NULL)
			{
				push(subStack_A, horse->data);
				horse = horse->next;
			}

			horse = subStack_A->cursor->next;
			while (horse != NULL)
			{
				printf("%c", horse->data);
				horse = horse->next;
			}
		}
	}


	//mainStack_B�� ���ڰ� ��������!

	if (mainStack_B->size > 0)
	{
		if (mainStack_B->cursor->next != NULL)
		{
			Node* horse = mainStack_B->cursor->next;

			while (horse != NULL)
			{
				printf("%c", horse->data);
				horse = horse->next;
			}
		}
	}
}
