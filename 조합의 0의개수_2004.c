#include<stdio.h>

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);

	int c = a - b;
	long long i;
	long long five1 = 0, five2 = 0, two1 = 0, two2 = 0;
	long long five3 = 0, two3 = 0;
	
	for (i = 2; i <= a; i *= 2)
	{
		two1 += a / i;
	}
	for (i = 5; i <= a; i *= 5)
	{
		five1 += a / i;
	}
	for ( i = 2; i <= b; i *= 2)
	{
		two2 += b / i;
	}
	for ( i = 5; i <= b; i *= 5)
	{
		five2 += b / i;
	}
	for ( i = 2; i <= c; i *= 2)
	{
		two3 += c / i;
	}
	for ( i = 5; i <= c; i *= 5)
	{
		five3 += c / i;
	}


	
	long long f_five = 0,f_two=0;
	
	f_two = two1-(two2 + two3);
	f_five = five1-(five2 + five3);

	if (f_five < f_two)printf("%lld", f_five);
	else printf("%lld", f_two);
	
	
}