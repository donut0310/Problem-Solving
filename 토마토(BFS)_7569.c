#include<stdio.h>



typedef struct listQueue {
	struct listQueue* next;
	int x, y;
}listQueue;

listQueue* front = NULL;
listQueue* rear = NULL;

int none = 0; //토마토가 들어있지 않은 칸
int cnt = 0; //처음 익어있던 토마토들
int N, M; //M행 N열
int box[1001][1001]; //처음 박스
int row[4] = { 0,1,0,-1 }; //상, 우, 하, 좌
int col[4] = { -1,0,1,0 }; //상, 우, 하, 좌
int date = 0; //날짜
int changed_tomato = 0; //영향받아 익어버린 토마토들
int max_tomato = 0; //토마토가 들어있는 칸의 개수

void push(int m, int n)
{
	listQueue* temp = (listQueue*)malloc(sizeof(listQueue));
	temp->next = NULL;
	temp->x = m;
	temp->y = n;

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
}

void pop()
{

	//큐에 한개만 있을때
	if (front == rear)
	{
		front = NULL;
		rear = NULL;
	}
	//큐에 여러개가 있을대
	else
	{
		listQueue* temp = front;
		front = front->next;
		temp = NULL;
	}
}

void check()
{
	listQueue* temp1 = front;
	listQueue* temp2 = rear;
	
	//
	while (temp1!=temp2)
	{
		for (int j = 0; j < 4; j++)
		{
			int nextX = temp1->x + row[j];
			int nextY = temp1->y + col[j];

			if ((nextX >= 0 && nextX < M) && (nextY >= 0 && nextY < N))
			{
				if (box[nextX][nextY] == 0)
				{
					push(nextX, nextY);
					box[nextX][nextY] = 1;
					changed_tomato++;
				}
			}
		}
		temp1 = temp1->next;
		pop();
	}
	//큐에 front와 rear가 같을때
	if (temp1 == temp2)
	{
		for (int j = 0; j < 4; j++)
		{
			int nextX = temp1->x + row[j];
			int nextY = temp1->y + col[j];

			if ((nextX >= 0 && nextX < M) && (nextY >= 0 && nextY < N))
			{
				if (box[nextX][nextY] == 0)
				{
					push(nextX, nextY);
					box[nextX][nextY] = 1;	
					changed_tomato++;
				}
			}
		}
		temp1 = temp1->next;
		pop();

	}
}

void bfs()
{
	while (1)
	{
		check();	
		if (front == NULL && rear == NULL)break;
		date++;
	}
	if (max_tomato == cnt + changed_tomato)printf("%d", date);
	else printf("-1");

}

int main()
{
	scanf("%d %d", &N, &M);


	for (int j = 0; j < M; j++)
	{
		for (int k = 0; k < N; k++)
		{
			scanf("%d", &box[j][k]);
			if (box[j][k] == 1)
			{
				cnt++;
				push(j, k);
			}
			else if (box[j][k] == -1)
				none++;
		}
	}
	if (cnt == N * M) {
		printf("0");
		return 0;
	}
	if (cnt == 0) {
		printf("-1");
		return;
	}

	max_tomato = (N*M) - none;

	bfs();
}