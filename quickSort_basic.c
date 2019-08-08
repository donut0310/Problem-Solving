//#include<stdio.h>
//#include<stdlib.h>
//
//#define max 10
//
//int partition(int a[], int start, int end)
//{
//	int pivot = a[end]; // 기준점 제일 오른쪽 element
//	int i;
//	int index = start; 
//
//	int temp;
//
//	for (i = start; i < end; i++)
//	{
//		if (a[i] <= pivot)
//		{
//			temp = a[i];
//			a[i] = a[index];
//			a[index] = temp;
//			index++;
//		}
//	}
//
//	temp = a[index];
//	a[index] = a[end];
//	a[end] = temp;
//	return index;
//}
//
//void QuickSort(int a[], int start, int end) {
//	int index;
//
//	if(start<end)
//	{
//		index = partition(a,start,end);
//
//		//맨 오른쪽에 element 이던 50의 위치가
//		//index에 저장되고 정렬이 마무리된 50의 이전 element에 pivot값을
//		//주기 위해 index-1을 보내준다
//		QuickSort(a,start,index-1);
//		
//		//50을 기준으로 왼쪽은 모두 정렬이 완료된 상태
//		//index는 50의 위치를 가리키고 있기때문에
//		//50의 다음위치부터 마지막 배열값까지 비교하기위해 
//		//index+1을 보내준다
//		QuickSort(a,index+1,end);
//
//	}
//	else
//	{
//		return;
//	}
//}
//
//int main()
//{
//	int a[max] = { 40,30,100,60,80,70,90,10,20,50 };
//	int i;
//
//	QuickSort(a, 0, max - 1);
//	for (i = 0; i < max; i++)
//	{
//		printf("%d ", a[i]);
//	}
//}