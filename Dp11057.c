#include<stdio.h>

int Dp[1001][10];

int main()
{
	int n;
	int sum = 0;

	scanf("%d", &n);

	//한자리 수 일때
	for (int i = 0; i < 10; i++)
	{
		Dp[1][i] = 1;
	}
	
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				Dp[i][j] = (Dp[i][j] + Dp[i - 1][k])%10007;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		sum = (sum + Dp[n][i])%10007;
	}
	printf("%d", sum);
	
}