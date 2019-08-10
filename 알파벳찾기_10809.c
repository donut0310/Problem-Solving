#include<stdio.h>
#include<string.h>

void compare(char input_word[], char alpha[] )
{
	int len = strlen(input_word);
	int cnt = 0;
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (alpha[i] == input_word[j])
			{
				cnt = 1;
				printf("%d ", j);
				break;
			}

		}
		if (cnt == 0)printf("%d ",-1);
		cnt = 0;
	}

}
int main()
{
	int j = 0;
	char alpha[26];
	char input_word[101];

	for (int i = 'a'; i <= 'z'; i++)
	{
		alpha[j] = i;
		j++;
	}
	scanf("%s", input_word);

	compare(input_word, alpha);


}