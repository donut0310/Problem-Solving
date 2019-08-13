#include<stdio.h>
#include<string.h>

void check(char data,int *cnt)
{
	if (*cnt == 0) {
		switch (data) {
		case '0' :
			break;
		case '1':
			printf("1");
			break;
		case '2':
			printf("10");
			break;
		case '3':
			printf("11");
			break;
		case '4':
			printf("100");
			break;
		case '5':
			printf("101");
			break;
		case '6':
			printf("110");
			break;
		case '7':
			printf("111");
			break;
		}
		*cnt += 1;
	}
	else
	{
		switch (data) {
		case '0':
			printf("000");
			break;
		case '1':
			printf("001");
			break;
		case '2':
			printf("010");
			break;
		case '3':
			printf("011");
			break;
		case '4':
			printf("100");
			break;
		case '5':
			printf("101");
			break;
		case '6':
			printf("110");
			break;
		case '7':
			printf("111");
			break;
		}
	}
}

int main()
{
	char input;
	int cnt = 0;
	while ((input = getchar()) != '\n')
	{
		if (input == '0' && cnt==0)continue;
		check(input,&cnt);
	}
	if (cnt == 0)printf("0");
}