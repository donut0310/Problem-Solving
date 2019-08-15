#include<stdio.h>

int main()
{
	int n;

	int m = 1;
	int cnt = 0;
	int input;
	int index = 0;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		
		while (m<=input)
		{
			if (input%m == 0)
				cnt++;
			m++;
		}
		if (cnt == 2)
		{
			index++;
		}
		cnt = 0;
		m = 1;
	}

	printf("%d", index);
}