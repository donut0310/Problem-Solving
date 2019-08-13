#include<stdio.h>
#include<string.h>

int main()
{
	char bin[1000005] = { '0','0'};

	scanf("%s", bin + 2);
	int len = strlen(bin);

	int i = 0;

	for (i = len % 3; i < len; i += 3)
	{
		printf("%d", (bin[i] - '0') * 4 + (bin[i + 1] - '0') * 2 + (bin[i + 2] - '0'));
	}
}