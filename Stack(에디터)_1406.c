#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//노드 껍데기
typedef struct Node {
	struct Node* next;

	char data;
}Node;

//노드 생성
Node* createNode(char data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}

//스택 껍데기
typedef struct listStack {
	Node* cursor;
	int size;
}listStack;

//스택 생성
void createStack(listStack** Stack)
{
	*Stack = (listStack*)malloc(sizeof(listStack));
	(*Stack)->cursor = NULL;
	(*Stack)->size = 0;
}

//push -> 입력 문자열 스택에 저장
void push(listStack* Stack, char data)
{
	Node* newNode = createNode(data);

	//스택이 비어있을때
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
		//B스택에 A스택의 커서데이터를 저장해줌
		//A스택의 커서데이터는 위치를 변경후 삭제
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
	//null값을 가진 cursor노드가 있기에 size=1
	if (mainStack_B->size == 1)
	{
		return;
	}
	else
	{
		Node* temp = mainStack_B->cursor->next;
		//A스택에 B스택의 커서데이터를 저장해줌
		//B스택의 커서데이터는 위치를 변경후 삭제

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
	//커서가 맨앞에 위치할때
	if (mainStack_A->cursor->next == NULL)
	{
		mainStack_A->cursor->next = addNode;
	}
	//커서앞에 노드가 존재할때
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
	//스택에 입력 문자열 저장
	for (int i = 0; i < len_str; i++)
	{
		push(mainStack_A, str[i]);
	}






	//명령어 횟수 입력
	scanf("%d", &num);


	for (int i = 0; i < num; i++)
	{
		getchar();
		//input --> 명령어
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
	//mainStack_A 거꾸로 저장해서 subStack을 출력한뒤에
	//mainStack_B의 문자 유무에 따라 출력

		//mainStack_A에 문자가 있을때만!
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


	//mainStack_B에 문자가 있을때만!

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
