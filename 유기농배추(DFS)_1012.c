#include<stdio.h>

int T; //Test Case
int m, n, k; //m 가로, n 세로, k 배추심어진 위치 개수
int map[50][50];
int x, y;
int cnt = 0; //지렁이 마리수
int row[4] = { 0,1,0,-1 };
int col[4] = { -1,0,1,0 };

void dfs(int x,int y)
{
	for (int i = 0; i < 4; i++)
	{
		int dx = x + row[i];
		int dy = y + col[i];
		if ((dx >= 0 && dx < m) && (dy >= 0 && dy < n))
		{
			if (map[dx][dy] == 1)
			{
				map[dx][dy] = 2;
				dfs(dx, dy);
			}
		}
	}
}

int main()
{
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d %d", &m, &n, &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d %d", &x, &y);
			map[x][y] = 1;
		}
		for (int k = 0; k < m; k++)
		{
			for (int r = 0; r < n; r++)
			{
				if (map[k][r] == 1)
				{
					map[k][r] = 2;
					cnt++;
					dfs(k,r);
				}
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
	}
}