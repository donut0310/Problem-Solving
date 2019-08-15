#include<stdio.h>

int arr[1000000];

int main()
{
	int a;
	int sum_max = 0;
	int check_num = 0;

	for (int i = 2; i <= 1000000; i++)
	{
		arr[i] = i;
	}

	for (int i = 2; i <= 1000000; i++)
	{
		if (arr[i] == 0)continue;
		for (int j = i + i; j <= 1000000; j += i)
		{
			arr[j] = 0;
		}
	}
	//입력 정수까지의 소수 찾기
	while (1)
	{
		scanf("%d", &a);
		if (a == 0)break;
		int flag = 0;

		for (int i = 2; i <= a; i++)
		{
				if (arr[i] != 0)
				{
					check_num = a - arr[i];
					if (arr[check_num] != 0)
					{
						printf("%d = %d + %d\n", a, arr[i], arr[check_num]);
						flag = 1; 
					}
				}
				if (flag == 1)break;
		}
		if (flag == 0)printf("Goldbach's conjecture is wrong.\n");
	}



}