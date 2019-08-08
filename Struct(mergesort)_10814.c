#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct person {
	int age;
	char name[101];
}person;

void merge(person* infor, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = 0;
	int len = (right - left + 1);
	person* sort = (person*)malloc(len * sizeof(person));

	while (i <= mid && j <= right) {
		//나이가 적은 사람 먼저 재정렬
		if ((infor + i)->age <= (infor + j)->age)
		{
			*(sort + k) = *(infor + i);
			i++;
		}
		else
		{
			*(sort + k) = *(infor + j);

			j++;
		}
		k++;
	}

	if (i > mid) {
		while (j <= right) {
			*(sort + k) = *(infor + j);

			k++;
			j++;
		}
	}
	else {
		while (i <= mid) {
			*(sort + k) = *(infor + i);
			k++;
			i++;
		}
	}
	k--;
	while (k >= 0)
	{
		*(infor + k + left) = *(sort + k);
		k--;
	}
}

void mergesort(person* infor,int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		mergesort(infor, left, mid);

		mergesort(infor, mid + 1, right);

		merge(infor,left,mid,right);
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	//n명의 정보를 저장할 구조체 n개 선언
	person *infor = (person*)malloc(n * sizeof(person));

	for (int i = 0; i < n; i++)
	{
		scanf("%d %s", &(infor + i)->age, &(infor + i)->name);
	}

	mergesort(infor, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		printf("%d %s\n", (infor + i)->age, (infor + i)->name);
	}

}
