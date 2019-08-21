#include<stdio.h>
#define max 6

//conquer - ��������
void merge(int a[], int low, int mid, int high)
{
	int b[1000];//ũ�� ���x
	int i = low;
	int j = mid + 1;
	int k = 0;

	//�� ���� ���������� �� ���̱�
	while (i <= mid && j<=high)
	{
		if (a[i] <= a[j]) {
			b[k] = a[i];
			k++;
			i++;
		}
		else {
			b[k] = a[j];
			k++;
			j++;
		}
	}

	//������ �����ִٸ�
	while (i <= mid)
	{
		b[k] = a[i];
		k++;
		i++;
	}
	//�������� �����ִٸ�
	while(j <= high)
	{
		b[k] = a[j];
		k++;
		j++;
	}
	k--;
	//���� �ۼ�
	while (k >= 0)
	{
		a[low + k] = b[k];
		k--;
	}
}

//divide - ����ǥ �ۼ�
void mergesort(int a[], int low, int high)
{
	//exit condition
	if (low < high)
	{
		int m = (low + high) / 2;

		//left
		mergesort(a, low, m);
		//right
		mergesort(a, m + 1, high);
		//fight
		merge(a, low, m, high);
	}
	//
	else
	{
		return;
	}
}


int main()
{
	int a[max] = { 20,10,70,80,40,90 };
	int i = 0;

	for (i = 0; i < max; i++)
	{
		printf(" %d", a[i]);
	}
	printf("\n");
	mergesort(a, 0, max - 1);
	for (i = 0; i < max; i++)
	{
		printf(" %d", a[i]);
	}

}