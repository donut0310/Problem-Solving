#include<stdio.h>

//���� X�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.
//
//X�� 3���� ������ ��������, 3���� ������.
//X�� 2�� ������ ��������, 2�� ������.
//1�� ����.
//���� N�� �־����� ��, ���� ���� ���� �� ���� ������ ����ؼ� 
//1�� ������� �Ѵ�.������ ����ϴ� Ƚ���� �ּڰ��� ����Ͻÿ�.

int Dp[1000001];

int min(int a, int b) {
	return a > b ? b : a;
}
int main()
{
	int num;
	scanf("%d", &num);

	Dp[1] = 0;
	for (int i = 2; i <= num; i++)
	{
		Dp[i] = Dp[i - 1] + 1;
		if (i % 2 == 0)
		{
			Dp[i] = min(Dp[i], Dp[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			Dp[i] = min(Dp[i], Dp[i / 3] + 1);
		}
	}

	printf("%d", Dp[num]);
}