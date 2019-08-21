#include<stdio.h>
typedef struct listQueue {
	struct listQueue* next;
	int x;
	int y;
}listQueue;

listQueue* front = NULL;
listQueue* rear = NULL;

int n;
int w, h;
int arr[51][51];
int row[4] = { 0,1,0,-1 };
int col[4] = { -1,0,1,0 };

int crosX[2] = { 1,-1 };
int crosY[2] = { -1,1 };
int cnt = 0;

void push(int x, int y)
{
	listQueue* temp = (listQueue*)malloc(sizeof(listQueue));
	temp->next = NULL;
	temp->x = x;
	temp->y = y;

	if (front == NULL && rear ==NULL)
	{
		front = temp;
		rear = temp;
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}
	arr[x][y] = 2;
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

int check(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int dx = x + row[i];
		int dy = y + col[i];
		
		if ((dx >= 0 && dx < h) && (dy >= 0 && dy < w))
		{
			if (arr[dx][dy] == 1)
			{
				push(dx, dy);
			}
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int dx = x + crosX[i];
			int dy = y + crosY[j];

			if ((dx >= 0 && dx < h) && (dy >= 0 && dy < w))
			{
				if (arr[dx][dy] == 1)
				{
					push(dx, dy);
				}
			}
		}
	}
}

void bfs()
{
	while (1)
	{
		check(front->x, front->y);
		pop();
		if (front == NULL)
		{
			cnt++;
			break;
		}
	}
}
int main()
{
	while (1)
	{
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0)break;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (arr[i][j] == 1)
				{
					push(i, j);
					bfs();
				}
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
		

	}
	
}