#include<stdio.h>


void merge(int *arr, int start, int mid, int end)
{
	int i = start;
	int j = mid + 1;
	int k = 0;
	int index = (end - start) + 1;
	int *brr = (int*)malloc(index * sizeof(int));

	while (i <= mid && j <= end)
	{
		if (arr[i] <= arr[j])
		{
			brr[k] = arr[i];
			i++;
		}
		else
		{
			brr[k] = arr[j];
			j++;
		}
		k++;
	}
	while (i <= mid)
	{
		brr[k] = arr[i];
		i++;
		k++;
	}
	while (j <= end)
	{
		brr[k] = arr[j];
		j++;
		k++;
	}
	k--;
	while (k >= 0)
	{
		arr[start + k] = brr[k];
		k--;
	}
	return;
}

void mergeSort(int *arr, int start, int end)
{
	int mid;
	if (start < end)
	{
		mid = (start + end) / 2;

		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
	else
	{
		return;
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	int *arr = (int*)malloc(n * sizeof(int));	

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	mergeSort(arr,0,n-1);

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
}