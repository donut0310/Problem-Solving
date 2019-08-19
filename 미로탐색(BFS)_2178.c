#include<stdio.h>
#include<stdlib.h>

typedef struct listQueue {
	int x;
	int y;
	struct listQueue* next;
}listQueue;

int maze[100][100];
int visit[100][100];
int n, m;
int row[4] = { 0,1,0,-1 };
int col[4] = { -1,0,1,0 };
int min_cnt=0;

listQueue* front = NULL;
listQueue* rear = NULL;

void push(int x, int y)
{
	listQueue* temp = (listQueue*)malloc(sizeof(listQueue));
	temp->x = x;
	temp->y = y;
	temp->next = NULL;

	//ť�� ���������
	if (front == NULL && rear == NULL)
	{
		rear = temp;
		front = temp;
		front->next = rear;
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}
}

void pop()
{
	//ť�� �Ѱ��� ������
	if (front == rear)
	{
		front = NULL;
		rear = NULL;
	}
	//ť�� ������ ������
	else
	{
		listQueue* temp = front;
		front = front->next;
		temp = NULL;
	}
}

void check(int x, int y)
{
	/*int row[4] = { 0,1,0,-1 };
	  int col[4] = { -1,0,1,0 };*/

	for (int i = 0; i < 4; i++)
	{
		int nextX = x + row[i];
		int nextY = y + col[i];

		if ((nextX >= 0 && nextX < n) && (nextY >= 0 && nextY < m))
		{
			if (maze[nextX][nextY] != 0 && visit[nextX][nextY] == 0)
			{
				visit[nextX][nextY] = visit[front->x][front->y]+1;
				push(nextX, nextY);
			}
		}
	}
}


void bfs()
{

	//���
	visit[0][0] = 1;

	//��� ���� ť�� ����
	push( 0, 0);

	

	while (1)
	{
		//���� �ִ� ���� üũ�ؼ� ť�� ����
		check(front->x, front->y);
		pop();
		
		//������ ��� ����
		if (front->x == n - 1 && front->y == m - 1)
		{
			printf("%d", visit[front->x][front->y]);
			break;
		}
	}


}

int main()
{


	scanf("%d %d", &n, &m);

	//�̷λ���
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &maze[i][j]);
		}
	}

	bfs();
	//�̷� ����
	
	
}