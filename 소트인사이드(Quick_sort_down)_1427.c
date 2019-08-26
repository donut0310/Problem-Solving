#include<stdio.h>

int partition(char *arr, int start, int end)
{
	char pivot = arr[start];
	int index = end;
	int temp;

	for (int i = end; i > start; i--)
	{
		if (arr[i] <= pivot)
		{
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			index--;
		}
	}

	temp = arr[index];
	arr[index] = arr[start];
	arr[start] = temp;
	return index;
}

void quickSort(char *arr, int start, int end)
{
	int index;
	if (start < end)
	{
		index = partition(arr,start,end);

		quickSort(arr,start,index-1);
		quickSort(arr,index+1,end);
	}
}

int main()
{
	int i = 0;
	char *arr,str[11];

	scanf("%s", str);

	int len = strlen(str);
	arr = (char*)malloc((len + 1) * sizeof(char));
	strcpy(arr, str);

	quickSort(arr,0,len-1);

	for (int i = 0; i < len; i++)
	{
		printf("%c", arr[i]);
	}
}