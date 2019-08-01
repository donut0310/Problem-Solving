#include<stdio.h>

int Dp[1001];


int main()
{
	int size;
	int arr[1001] = { 0 };
	int x[1001] = { 0 };
	int max = Dp[0];
	scanf("%d", &size); 

	
	for (int i = 1; i <= size; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	

	for (int i = 1; i <= size; i++)
	{
		int min = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				if (Dp[j] > min)
				{
					min = Dp[j];
				}
			}
		}
		Dp[i] = min + 1;
		if (Dp[i] > max)max = Dp[i];
	}


	printf("%d", max);

}