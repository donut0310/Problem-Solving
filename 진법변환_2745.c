#include<stdio.h>
#include<string.h>

int main()
{
	char str[100];
	
	scanf("%s", str);
	int len = strlen(str);
	int n;
	int sum = 0;
	scanf("%d", &n);

	int cnt = 1;
	for (int i = len - 1; i >= 0; i--)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			sum += (str[i] - 48 ) * cnt;
		}
		else
		{
			sum += (str[i] -55 )*cnt;
		}
		cnt*=n;
	}
	printf("%d", sum);
}