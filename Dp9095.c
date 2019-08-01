#include<stdio.h>

Dp[12];

int main()
{
	int test_case;
	int num;

	scanf("%d", &test_case);
	
	Dp[0] = 1;
	Dp[1] = 2;
	Dp[2] = 4;
	for (int i = 3; i < 11; i++)
	{
		Dp[i] = Dp[i - 3] + Dp[i - 2] + Dp[i - 1];
	}
	for (int i = 0; i < test_case; i++)
	{
		scanf("%d", &num);
		printf("%d\n", Dp[num-1]);
	}
	
}