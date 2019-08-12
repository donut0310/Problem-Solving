#include<stdio.h>

int main()
{
	int a, b;
	int min = 1, max = 1;
	int cnt = 1;
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		while (a >= cnt && b >= cnt)
		{
			if (a%cnt == 0 && b%cnt == 0)
			{
				min = cnt;
			}
			cnt++;
		}
		max = min * (a / min)*(b / min);

		printf("%d\n", max);
		min = 1; max = 1; cnt = 1;

	}

	
}