#include<stdio.h>
#include<string.h>

int main()
{
	char str[101];


	while(gets(str)) //�Է� ���� ������ ���⿡ ������ EOF������ �־���
	{
		int lower = 0, upper = 0, numcnt = 0, space = 0;
		int len = strlen(str);

		for(int i=0;i<len;i++)
		{
			
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				upper++;
			}
			else if (str[i] >= 'a' && str[i] <= 'z')
			{
				lower++;
			}

			else if (str[i] == ' ')
			{
				space++;
			}
			else if (str[i] >= 48 && str[i] <= 57)
			{
				numcnt++;
			}
		}
		printf("%d %d %d %d\n", lower, upper, numcnt, space);

	}

}