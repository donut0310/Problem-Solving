#include<stdio.h>
#include<string.h>

int main()
{
	int a, b;
	int arr[100];
	int i = 0;
	scanf("%d %d", &a, &b);

	while (a!=0)
	{
		arr[i] = a % b;
		a /= b;
		i++;
	}
	
	for (int j = i - 1; j >= 0; j--)
	{

		if (arr[j] >= 10)
		{
			arr[j] += 55;
			printf("%c", arr[j]);
		}
		else
		{
			printf("%d", arr[j]);
		}
	}
}