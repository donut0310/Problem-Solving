#include<stdio.h>

#define max 5000000

int arr[max];
int sort[max];

void merge(int arr[], int start, int mid, int end)
{
	int i = start;
	int j = mid + 1;
	int index = 0;

	while (i <= mid && j <= end)
	{
		if (arr[i] <= arr[j])
		{
			sort[index] = arr[i];
			i++;
		}
		else {
			sort[index] = arr[j];
			j++;
		}
		index++;
	}
	while (i <= mid)
	{
		sort[index] = arr[i];
		i++; index++;
	}
	while (j <= end)
	{
		sort[index] = arr[j];
		j++; index++;
	}
	index--;
	while (index >= 0)
	{
		arr[index + start] = sort[index];
		index--;
	}
}

void mergesort(int arr[],int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;

		mergesort(arr, start, mid);
		
		mergesort(arr, mid + 1, end);

		merge(arr, start, mid, end);

	}
	else
	{
		return;
	}
}

int main()
{
	int n,k;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	mergesort(arr, 0, n - 1);

	printf("%d", arr[k-1]);
}