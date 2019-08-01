#include<stdio.h>

long long Dp[91];

int main()
{
	int n;
	scanf("%d", &n);


	Dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		Dp[i] = Dp[i - 1] + Dp[i - 2];
	}
	printf("%lld", Dp[n]);
}