//#include<stdio.h>
//#include<stdlib.h>
//
//#define max 10
//
//int partition(int a[], int start, int end)
//{
//	int pivot = a[end]; // ������ ���� ������ element
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
//		//�� �����ʿ� element �̴� 50�� ��ġ��
//		//index�� ����ǰ� ������ �������� 50�� ���� element�� pivot����
//		//�ֱ� ���� index-1�� �����ش�
//		QuickSort(a,start,index-1);
//		
//		//50�� �������� ������ ��� ������ �Ϸ�� ����
//		//index�� 50�� ��ġ�� ����Ű�� �ֱ⶧����
//		//50�� ������ġ���� ������ �迭������ ���ϱ����� 
//		//index+1�� �����ش�
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