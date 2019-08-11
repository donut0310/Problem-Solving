#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int a,b,c,d;
	long long ab=0, cd=0;
	long long n = 1;
	int cnt1 = 0,cnt2 = 0;
	int arr1[100], arr2[100];
	
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int i = 0;
	while (b != 0)
	{
		arr1[i] = b % 10;
		b /= 10;
		cnt1++;
		i++;
	}
	while (a != 0)
	{
		arr1[i] = a % 10;
		a /= 10;
		cnt1++;
		i++;
	}

	for (int i = 0; i < cnt1; i++)
	{
		ab += (arr1[i] * n);
		n *= 10;
	}

	//////////////////////////////////
	int j = 0;
	n = 1;
	while (d != 0)
	{
		arr2[j] = d % 10;
		d /= 10;
		cnt2++;
		j++;
	}
	while (c != 0)
	{
		arr2[j] = c % 10;
		c /= 10;
		cnt2++;
		j++;
	}


	for (int i = 0; i < cnt2; i++)
	{
		cd += (arr2[i] * n);
		n *= 10;
	}
	printf("%lld",ab+cd);

}