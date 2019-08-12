#include<stdio.h>


int main()
{
	int a, b;
	int cnt = 1;
	int min = 1, max = 1;

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

	printf("%d\n", min);
	printf("%d", max);

}