#include<stdio.h>

// 문제

//2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 
//방법의 수를 구하는 프로그램을 작성하시오.
//아래 그림은 2×5 크기의 직사각형을 채운
//한 가지 방법의 예이다.

int Dp[1001];

int main()
{
	int n;
	scanf("%d", &n);
	Dp[0] = 1;
	Dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		Dp[i] = (Dp[i - 1] + Dp[i - 2]) % 10007;
	}
	printf("%d", Dp[n]);

}