#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//////////////////////////////////////////////////
//////퀵소트는 중복값이 많으면 성능이 떨어짐//////
//따라서 중복문자를 먼저 제거한 후에 퀵소트 실행//
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
			//길이가 같을때 사전순으로
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
	//2차원 문자열 배열에 각 메모리에 맞게 문자열 저장 

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