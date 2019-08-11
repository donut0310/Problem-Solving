#include<stdio.h>
#include<string.h>

int partition(char** arr, int start, int end)
{
	char *pivot = arr[end];
	int i;
	int index = start;

	char* temp;
	for (i = start; i < end; i++)
	{
		if (strcmp(arr[i], pivot) < 0)
		{
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			index++;
		}
	}
	temp = arr[index];
	arr[index] = arr[end];
	arr[end] = temp;
	return index;
}

void quicksort(char **arr, int start, int end)
{
	if (start < end)
	{
		int index = partition(arr, start, end);

		quicksort(arr, start, index - 1);

		quicksort(arr, index + 1, end);
	}
	else
	{
		return;
	}
}

int main()
{
	char str[1001], *pstr;
	char **arr;

	gets(str);
	int len = strlen(str);

	pstr = (char*)malloc(sizeof(char)*(len + 1));
	strcpy(pstr, str);

	
	arr = (char**)malloc(sizeof(char*)*(len));
	
	for (int i = 0; i < len; i++)
	{
		arr[i] = (char*)malloc((len - i + 1)*sizeof(char));
		strcpy(arr[i], pstr + i);
	}

	quicksort(arr, 0, len - 1);

	for (int i = 0; i < len; i++)
	{
		printf("%s\n", arr[i]);
	}


}