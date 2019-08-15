#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int sum = 1;

	while (n != 0)
	{
		sum *= n;
		n--;
	}
	printf("%d", sum);
}