//#include<stdio.h>
//#include<stdlib.h>
//
//
//void merge(int *a, int low, int mid, int high)
//{
//	int i = low;
//	int j = mid + 1;
//	int k = 0;
//	int len = high - low + 1;
//	int *sort = (int*)malloc(len*sizeof(int));
//
//	while (i <= mid && j <= high) {
//		if (a[i] <= a[j])
//		{
//			sort[k] = a[i];
//			i++;
//		}
//		else
//		{
//			sort[k] = a[j];
//			j++;
//		}
//		k++;
//	}
//	//오른쪽이 남아있을때
//	if (i > mid) {
//		while (j <= high) {
//			sort[k] = a[j];
//			k++;
//			j++;
//		}
//	}
//	//왼쪽이 남아있을때
//	else {
//		while (i <= mid) {
//			sort[k] = a[i];
//			i++;
//			k++;
//		}
//	}
//
//	k--;
//	while (k >= 0) {
//		a[k + low] = sort[k];
//		k--;
//	}
//	
//}
//
//void mergesort(int *a, int low, int high)
//{
//	if (low < high)
//	{
//		int m = (low + high) / 2;
//		//left
//		mergesort(a, low, m);
//		//right
//		mergesort(a, m + 1, high);
//		//fight
//		merge(a, low, m, high);
//	}
//
//}
//
//int main()
//{
//	
//	int input_num;
//	scanf("%d", &input_num);
//	int *arr = (int *)malloc(sizeof(int)*input_num);
//
//	for (int i = 0; i < input_num; i++)
//	{
//		scanf("%d", arr+i);
//	}
//
//	mergesort(arr, 0, input_num - 1);
//
//	for (int i=0;i<input_num; i++)
//	{
//		printf("%d\n", *(arr + i));
//	}
//	
//}