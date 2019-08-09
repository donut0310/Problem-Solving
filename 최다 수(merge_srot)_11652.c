#include<stdio.h>
#include<stdlib.h>
//입력 값들 중 가장 많이 입력된 값 출력하기
//모든 입력값을 오름차순으로 정렬한다 
//(가장 많이 입력된값이 여러개일경우 가장작은 입력값을 출력하기위해)
//각 원소를 이전 값과 비교해서 같으면 cnt++
//max를 찾고 해당 값을 저장

#define max 1000000

long long arr[max];
long long brr[max];
void merge(long long arr[], int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = 0;

	int len = right - left + 1;

	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			brr[k] = arr[i];
			i++;
		}
		else {
			brr[k] = arr[j];
			j++;
		}
		k++;
	}
	//오른쪽이 남아있다면
	if (i > mid) {
		while (j <= right)
		{
			brr[k] = arr[j];
			j++;
			k++;
		}
	}
	//왼쪽이 남아있다면
	else {
		while (i <= mid)
		{
			brr[k] = arr[i];
			i++;
			k++;
		}
	}
	k--;
	while (k >= 0)
	{
		arr[left + k] = brr[k];
		k--;
	}

}

void mergesort(long long arr[],int left,int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		mergesort(arr, left, mid);
		
		mergesort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
	else
	{
		return;
	}
}

int main()
{
	int n;
	int max_cnt=1;
	int cnt = 1;
	
	scanf("%d", &n);
	

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
	}
	mergesort(arr, 0, n - 1);

	
	long long result = arr[0];


	/*for (int i = 0; i < n; i++)
	{
		printf(" %lld", arr[i]);
	}
	printf("\n");*/
	for (int i = 1; i < n; i++)
	{
		if (arr[i] == arr[i-1])
		{
			cnt++;
		}
		else cnt = 1;
		if (cnt > max_cnt)
		{
			max_cnt = cnt;
			result = arr[i];
		}
	}

	printf("%lld",result);


}