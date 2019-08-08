#include<stdio.h>
#include<stdlib.h>

typedef struct dot {
	int x;
	int y;
}dot;

void merge(dot* base, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = 0;
	int len = right - left + 1;

	dot* sort = (dot*)malloc(len * sizeof(dot));

	while (i <= mid && j <= right)
	{
		if ((base + i)->x < (base + j)->x)
		{
			*(sort + k) = *(base + i);
			i++;
		}
		else if ((base + i)->x == (base + j)->x)
		{
			if ((base + i)->y <= (base + j)->y)
			{
				*(sort + k) = *(base + i);
				i++;
			}
			else
			{
				*(sort + k) = *(base + j);
				j++;
			}
		}
		else
		{
			*(sort + k) = *(base + j);
			j++;
		}
		k++;
	}
	if (i > mid)
	{
		while (j <= right)
		{
			*(sort + k) = *(base + j);
			j++;
			k++;
		}
	}
	else
	{
		while (i <= mid)
		{
			*(sort + k) = *(base + i);
			i++;
			k++;
		}
	}
	k--;
	while (k >= 0)
	{
		*(base + left + k) = *(sort + k);
		k--;
	}
}

void mergesort(dot* base, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		mergesort(base, left, mid);
		mergesort(base, mid + 1, right);
		merge(base, left, mid, right);
	}
	else
	{
		return;
	}
}

int main()
{
	dot* base;
	int n;
	scanf("%d", &n);
	
	base = (dot*)malloc(n*sizeof(dot));
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &(base + i)->x, &(base + i)->y);
	}

	mergesort(base,0,n-1);

	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", (base + i)->x, (base + i)->y);
	}
}