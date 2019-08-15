#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int two = 0, five = 0;


	for (int i = 2; i <= n; i*=2)
	{
		two += n / i;
	}
	for (int i = 5; i <= n; i *= 5)
	{
		five += n / i;
	}
	if (two > five)printf("%d", five);
	else printf("%d", two);
}