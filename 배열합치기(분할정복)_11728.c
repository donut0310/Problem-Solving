#include<stdio.h>
int n, m;

void merge(int *C, int start, int mid, int end)
{
	int *B = (int*)malloc((n + m) * sizeof(int));

	int i = start;
	int j = mid + 1;
	int index = 0;

	//한쪽이 끝날떄까지
	while (i <= mid && j <= end)
	{
		if (C[i] <= C[j])
		{
			B[index] = C[i];
			i++;
		}
		else
		{
			B[index] = C[j];
			j++;
		}
		index++;

	}
	
	//왼쪽이 남았을때
	while (i <= mid)
	{
		B[index] = C[i];
		index++;
		i++;
	}
	//오른쪽이 남았을때
	while (j <= end)
	{
		B[index] = C[j];
		index++;
		j++;
	}
	index--;
	while (index >= 0)
	{
		C[start + index] = B[index];
		index--;
	}
	free(B);
}

void mergeSort(int* C, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;

		mergeSort(C, start, mid);

		mergeSort(C, mid + 1, end);

		merge(C, start, mid, end);

	}
	else
	{
		return;
	}
}

int main()
{
	int *A, *B, *C;
	
	scanf("%d %d", &n, &m);
	A = (int*)malloc(n * sizeof(int));
	B = (int*)malloc(m * sizeof(int));
	C = (int*)malloc((n + m) * sizeof(int));
	
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", A + i);
		C[i] = A[i];
	}
	for (int j = 0; j < m; j++)
	{
		scanf("%d", B + j);
		C[i] = B[j];
		i++;
	}

	free(A);
	free(B);
	
	mergeSort(C,0, n + m - 1);

	for (i = 0; i < n + m; i++)
	{
		printf("%d ", C[i]);
	}
}