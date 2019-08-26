#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//////////////////////////////////////////////////
//////����Ʈ�� �ߺ����� ������ ������ ������//////
//���� �ߺ����ڸ� ���� ������ �Ŀ� ����Ʈ ����//
//////////////////////////////////////////////////

int partition(char **arr, int start, int end)
{
	char *pivot = arr[end];
	int index = start;
	char* temp;

	for (int i = start; i < end; i++)
	{
		int arr_len = strlen(arr[i]);
		int piv_len = strlen(pivot);

		if (arr_len <= piv_len)
		{
			//���̰� ������ ����������
			if (arr_len == piv_len)
			{
				if (strcmp(arr[i], pivot) < 0)
				{
					temp = arr[i];
					arr[i] = arr[index];
					arr[index] = temp;
					index++;
				}
			}
			else
			{
				temp = arr[i];
				arr[i] = arr[index];
				arr[index] = temp;
				index++;
			}
		}
	}
	temp = arr[index];
	arr[index] = arr[end];
	arr[end] = temp;
	return index;
}

void quickSort(char **arr,int start, int end)
{
	int index;
	if (start < end)
	{
		index = partition(arr, start, end);

		quickSort(arr,start,index-1);
		quickSort(arr,index+1,end);
	}
	else
	{
		return;
	}
}

void check(char** arr,  int n)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != "\0")
		{
			for (int j = i + 1; j < n; j++)
			{
			
				if (strcmp(arr[i], arr[j]) == 0)
				{
					arr[j] = "\0";
				}
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	int **arr=NULL;
	char input[51];

	arr = (char**)malloc(n * sizeof(char*));
	//2���� ���ڿ� �迭�� �� �޸𸮿� �°� ���ڿ� ���� 

	for (int i = 0; i < n; i++)
	{
		scanf("%s", input);
		int len = strlen(input);
		arr[i] = (char*)malloc((len + 1) * sizeof(char));
		strcpy(arr[i], input);
	}
	
	check(arr, n);

	quickSort(arr,0,n-1);

	

	for (int i = 0; i < n; i++)
	{
		if(arr[i]!="\0")printf("%s\n", arr[i]);
	}
}