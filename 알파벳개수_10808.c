#include<stdio.h>
#include<string.h>

int return_arr[26];

void compare(char word[], char alpha[], int* return_arr)
{
	int len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (word[i] == alpha[j])
			{
				return_arr[j] = return_arr[j] + 1;
				break;
			}
		}
	}

	for (int i = 0; i < 26; i++)
	{
		printf("%d ", return_arr[i]);
	}
}

int main()
{
	char word[101];
	int j=0;

	char alpha[26];
	for (int i = 'a'; i <= 'z'; i++)
	{
		alpha[j] = i;
		j++;
	}

	scanf("%s", word);

	compare(word,alpha,return_arr);


}