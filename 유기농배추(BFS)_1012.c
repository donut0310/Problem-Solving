#include<stdio.h>

typedef struct listQueue {
	struct listQueue* next;
	int x, y;
}listQueue;

//////////////변수/////////////
int T;  //test case
int m, n, k; // m 가로, n 세로, k 배추 위치 개수
int map[50][50];
int cnt = 0; //지렁이 마리수

int row[4] = { 0,1,0,-1 };
int col[4] = { -1,0,1,0 };
listQueue* front = NULL;
listQueue* rear = NULL;
///////////////////////////////

void push(int i, int j)
{
	listQueue* temp = (listQueue*)malloc(sizeof(listQueue));
	temp->x = i;
	temp->y = j;
	temp->next = NULL;
	if (front == NULL && rear == NULL)
	{
		front = temp;
		rear = temp;
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}
	map[i][j] = 2;
}

void pop()
{
	if (front == rear)
	{
		front = NULL;
		rear = NULL;
	}
	else
	{
		listQueue* temp = front;
		front = front->next;
		temp = NULL;
	}
}

void check()
{
	for (int i = 0; i < 4; i++)
	{
		int nextX = front->x + row[i];
		int nextY = front->y + col[i];
		if ((nextX >= 0 && nextX < m) && (nextY >= 0 && nextY < n))
		{
			if (map[nextX][nextY] == 1)
			{
				push(nextX, nextY);
			}
		}
	}
}

void bfs()
{
	while (1)
	{
		check();
		pop();
		if (front == NULL)break;
	}
}

int main()
{
	int X, Y;
	scanf("%d", &T);
	for (int i = 0; i < T;i++)
	{
		scanf("%d %d %d", &m, &n, &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d %d", &X, &Y);
			map[X][Y] = 1;
		}
		for (int k = 0; k < m; k++)
		{
			for (int r = 0; r < n; r++)
			{
				if (map[k][r] == 1)
				{
					push(k, r);
					bfs();
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
	}
}