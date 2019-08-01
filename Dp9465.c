#include<stdio.h>

int Dp[2][1000001];

int Max(int a, int b) { return a > b ? a : b; }

int main()
{

	
	int t, n;
	int a[2][100001];
	scanf("%d", &t);



	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);

		for (int j = 0; j < 2; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				scanf("%d", &a[j][k]);
			}
			Dp[0][0] = Dp[1][0] = 0;
			Dp[0][1] = a[0][1];
			Dp[1][1] = a[1][1];

			for (int q = 2; q <= n; q++)
			{
				Dp[0][q] = Max(Dp[1][q - 1], Dp[1][q - 2]) + a[0][q];
				Dp[1][q] = Max(Dp[0][q - 1], Dp[0][q - 2]) + a[1][q];
			}

		}
		printf("%d\n", Max(Dp[0][n], Dp[1][n]));

	}



	
}