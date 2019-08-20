#include<stdio.h>
#define MAX 1001
typedef enum { false, true } boolean;

int map[MAX][MAX];
boolean visited[MAX];

int n, m, v; ///n 정점개수 m 간선개수 v 시작정점 번호

int queue[MAX];
int front;
int rear;

boolean empty()
{
	return(front == rear);
}
//////////////////////////////////

void enqueue(int v)
{
	queue[++rear] = v;
}

int dequeue()
{
	return queue[++front];
}

void dfs(int data)
{
	visited[data] = true;
	printf("%d ", data);

	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false && map[data][i] == 1)
		{
			dfs(i);
		}
	}
}

void bfs(int v)
{
	enqueue(v);
	visited[v] = true;

	while (!empty())
	{
		int x = dequeue();
		printf("%d ", x);

		for (int i = 1; i <= n; i++)
		{
			if (visited[i] == false && map[x][i] == 1)
			{
				enqueue(i);
				visited[i] = true;
			}
		}
	}

}

void reset()
{
	for (int i = 0; i <= n; i++)
	{
		visited[i] = false; //0값 초기화
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &v);
	int x, y;

	//정점 데이터 저장
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		map[x][y] = 1;
		map[y][x] = 1;

	}

	dfs(v);
	printf("\n");
	reset();
	bfs(v);
}
