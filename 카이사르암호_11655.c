#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void ROT13(char *input,int len)
{
	//알파벳을 13글자씩 밀어서 저장
	//알파벳 대문자와 소문자만 적용

	char *change = (char*)malloc((len + 1) * sizeof(char));
	strcpy(change, input);

	
	for (int i = 0; i < len; i++)
	{
		//소문자일때
		if (*(input+i) >= 'a' && *(input + i) <= 'z')
		{
			if (*(input + i) > 'm')
			{
				*(change + i) -= 13;
			}
			else
			{
				*(change + i) += 13;
			}
		}
		//대문자일때
		else if (*(input + i) >= 'A' && *(input + i) <= 'Z')
		{
			if (*(input + i) > 'M')
			{
				*(change + i) -= 13;
			}
			else
			{
				*(change + i) += 13;
			}
		}
	}
	printf("%s", change);

}

int main()
{
	char str[101],*input;

	gets(str);
	int len = strlen(str);
	input = (char*)malloc((len + 1) * sizeof(char));
	strcpy(input, str);

	ROT13(input,len);
}