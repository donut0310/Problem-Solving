#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void ROT13(char *input,int len)
{
	//���ĺ��� 13���ھ� �о ����
	//���ĺ� �빮�ڿ� �ҹ��ڸ� ����

	char *change = (char*)malloc((len + 1) * sizeof(char));
	strcpy(change, input);

	
	for (int i = 0; i < len; i++)
	{
		//�ҹ����϶�
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
		//�빮���϶�
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