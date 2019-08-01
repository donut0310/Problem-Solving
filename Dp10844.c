#include<stdio.h>

int Dp[101][10];

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

	//두자리 수 이상일때
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				Dp[i][0] = (Dp[i - 1][1])%1000000000;
			}
			else if (j == 9)
			{
				Dp[i][9] = (Dp[i - 1][8]) % 1000000000;
			}
			else
			{
				Dp[i][j] = (Dp[i - 1][j - 1] + Dp[i - 1][j + 1]) % 1000000000;
			}
		}
	}


	for (int i = 1; i < 10; i++)
	{
		sum = (sum + Dp[n][i]) % 1000000000;
	}

	printf("%d", sum);

}