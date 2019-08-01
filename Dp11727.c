#include<stdio.h>

int Dp[1001];

int main()
{
	int n;
	scanf("%d", &n);

	Dp[0] = 1;
	Dp[1] = 3;
	for (int i = 2; i < n; i++)
	{
		Dp[i] = ((Dp[i - 2] * 2) + Dp[i - 1]) % 10007;
	} 

	printf("%d", Dp[n-1]);
}
