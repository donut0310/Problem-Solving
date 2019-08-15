#include<stdio.h>

int main()
{
	int n;
	int a=2;
	int i = 0;

	int arr[1000];
	scanf("%d", &n);
	int m = n;

	if (n == 0)
		printf("0");

	while (n != 0)
	{
		if (n == 1)
		{
			arr[i] = 1;
			i++;
			break;
		}
		else if (n % 2 == 0)
		{
			arr[i] = 0;
			n /= -2;
		}
		else
		{
			arr[i] = 1;
			n = -(n - 1) / 2;
		}
		i++;
	}

	i--;
	for (int j = i; j >=0 ; j--)
		{
			printf("%d", arr[j]);
		}

}