#include<stdio.h>


int map[26][26];
int m;
int house_cnt = 0;
int arr[626];
int row[4] = { 0,1,0,-1 };
int col[4] = { -1,0,1,0 };
int arr_index = 0;

void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int dx = x + row[i];
		int dy = y + col[i];
		if ((dx >= 0 && dx < m) && (dy >= 0 && dy < m))
		{
			if (map[dx][dy] == 1)
			{
				map[dx][dy] = 2;
				house_cnt++;
				dfs(dx, dy);
			}
		}
	}
}

int partition(int start, int end)
{
	int pivot = arr[end];
	int i;
	int index = start;
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
		quick(start, index - 1);
		quick(index+1,end);
	}
}

int main()
{
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1)
			{
				map[i][j] = 2;
				house_cnt++;
				dfs(i, j);
				arr[arr_index] = house_cnt;
				house_cnt = 0;
				arr_index++;
			}
		}
	}
	quick(0, arr_index-1);

	printf("%d\n", arr_index);
	for (int i = 0; i < arr_index; i++)
	{
		printf("%d\n", arr[i]);
	}

}
