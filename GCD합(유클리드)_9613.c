#include<stdio.h>

int GCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return GCD(b, a%b);
	}
}

int main()
{
	int t;
	int n;
	int arr[101];

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		long long sum = 0;
		scanf("%d", &n);
		
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[j]);
		}
		for (int j = 0; j < n-1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				sum += GCD(arr[j],arr[k]);
			}
		}
		printf("%lld\n", sum);
	}
}