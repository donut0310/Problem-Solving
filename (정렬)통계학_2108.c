#include<stdio.h>

double SUM = 0; //산술평균을 위한 값 총합/N

int count[8001];
int max[8001];
//mergeSort 중앙값 찾기 위함, 최댓값 최솟값 차이 알기 위함
void merge(int *arr, int start, int mid, int end)
{
	int i = start;
	int j = mid + 1;
	int k = 0;
	int index = end - start + 1;
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
////////////////////////////////////

//산술평균
void AVR(int n)
{
	printf("%.lf\n", SUM / n);

}
//////////

//중앙값
void MID(int* arr, int n)
{
	printf("%d\n", arr[(n+1) / 2-1]);

}
//////////

//최빈값
void FREQ(int *arr, int n)
{
	int k = 0;
	int max_cnt = count[0];
	int j = 0;
	max[1] = NULL;
	for (int i = 0; i < 8001; i++)
	{
		if (count[i] > max_cnt)
		{
			k = 0;
			max[1] = NULL;
			max_cnt = count[i];
			max[k++] = i - 4000;//해당 arr배열 값 저장
		}
		else if (count[i] == max_cnt)
		{
			max[k++] = i - 4000;
		}
		if (count[i] > 0)
		{
			while (count[i] > 0)
			{
				arr[j++] = i - 4000;
				count[i]--;
			}
		}
	}
	if (max[1] == NULL)
	{
		printf("%d\n", max[0]);
	}
	else
	{
		printf("%d\n", max[1]);
	}
}
/////////

//범위
void RAN(int* arr, int n)
{
	int result = arr[n - 1] - arr[0];
	printf("%d\n", result);
}
/////////
int main()
{
	int n;
	scanf("%d", &n);

	int *arr = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		SUM += arr[i];
		count[arr[i] + 4000]++;
	}


	mergeSort(arr, 0, n - 1);


	AVR(n);
	MID(arr, n);
	FREQ(arr, n);
	RAN(arr, n);
}
