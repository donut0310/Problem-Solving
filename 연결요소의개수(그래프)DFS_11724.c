#include<stdio.h>
#define MAX 1001

typedef enum {
	false, true 
}boolean;


int n, m; // 정점, 간선
int x, y;
int cnt = 0;

int map[MAX][MAX];
boolean visited[MAX];


void dfs(int x)
{
	visited[x] = true;

	for (int i = 1; i <= n; i++)
	{
		if (map[x][i] == 1 && visited[i]==false)
		{
			dfs(i);
		}
	}
}

int main()
{
	int inputx, inputy;
	scanf("%d %d", &n, &m);
	

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &inputx,&inputy);
		map[inputx][inputy] = 1;
		map[inputy][inputx] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		visited[i] = false;
	}

	
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false)
		{
			dfs(i);
			cnt++;
		}
	}
	

	printf("%d", cnt);
}