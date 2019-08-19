#include<stdio.h>

int n;
int map[26][26];
int arr[626];

typedef struct listQueue {
	struct listQueue* next;
	int x, y;
}listQueue;

listQueue* front = NULL;
listQueue* rear = NULL;
int row[4] = { 0,1,0,-1 }; //상, 우, 하, 좌
int col[4] = { -1,0,1,0 }; //상, 우, 하, 좌
int cnt = 0; //단지내 집 개수
int arr_index=0; //배열 인덱스

void push(int i,int j)
{
	listQueue* temp = (listQueue*)malloc(sizeof(listQueue));
	temp->x = i;
	temp->y = j;
	temp->next = NULL;

	//큐가 비어있을때
	if (front == NULL && rear == NULL)
	{
		front = temp;
		rear = temp;
		front->next = rear;
	}
	//큐가 비어있지 않을때
	else
	{
		rear->next = temp;
		rear = temp;
	}
	cnt++;
	map[i][j] = 2;

}

void pop()
{
	//큐에 하나만 있을때
	if (front == rear)
	{
		front = NULL;
		rear = NULL;
	}
	//큐에 여러개가 있을때
	else
	{
		listQueue* temp = front;
		front = front->next;
		temp = NULL;
	}
}

check(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + row[i];
		int nextY = y + col[i];

		if ((nextX >= 0 && nextX < n) && (nextY >= 0 && nextY < n))
		{
			if (map[nextX][nextY] == 1)
			{
				push(nextX,nextY);
			}
		}
	}

}

void bfs()
{
	while (1)
	{
		//단지 조사
		check(front->x, front->y);
		pop();
		if (front == NULL)
		{
			arr[arr_index] = cnt;
			arr_index++;
			break;
		}
	}
}

int partition(int start, int end)
{
	int pivot = arr[end];
	int i;
	int index=start;
	int temp;

	for (i = start; i < end; i++)
	{
		if (arr[i] <= pivot)
		{
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			index++;
		}
	}
	temp = arr[index];
	arr[index] = arr[end];
	arr[end] = temp;
	return index;
}

void quick(int start,int end)
{
	int index;
	if (start < end)
	{
		index = partition(start, end);

		quick(start, index-1);

		quick(index+1, end );
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1)
			{
				push(i,j);
				bfs();
				cnt = 0;
			}
		}
	}

	quick(0,arr_index-1);

	printf("%d\n", arr_index);
	for (int i = 0; i < arr_index; i++)
	{
		printf("%d\n", arr[i]);
	}
}
