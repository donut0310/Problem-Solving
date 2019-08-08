#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct stu {
	char name[11];
	int kor;
	int eng;
	int math;
}stu;

int partition(stu* people, int start, int end)
{
	stu* pivot = (stu*)malloc(sizeof(stu));
	*pivot = *(people + end);
	int i;
	int index = start;

	stu temp;

	for (i = start; i < end; i++)
	{
		if ((people + i)->kor > pivot->kor)
		{
			temp = *(people + i);
			*(people + i) = *(people + index);
			*(people + index) = temp;
			index++;
		}
		else if ((people + i)->kor == pivot->kor &&
			(people + i)->eng < pivot->eng)
		{
			temp = *(people + i);
			*(people + i) = *(people + index);
			*(people + index) = temp;
			index++;
		}
		else if ((people + i)->kor == pivot->kor &&
			(people + i)->eng == pivot->eng &&
			(people + i)->math > pivot->math)
		{
			temp = *(people + i);
			*(people + i) = *(people + index);
			*(people + index) = temp;
			index++;
		}
		else if ((people + i)->kor == pivot->kor &&
			(people + i)->eng == pivot->eng &&
			(people + i)->math == pivot->math &&
			strcmp((people + i)->name, pivot->name) < 0)
		{
			temp = *(people + i);
			*(people + i) = *(people + index);
			*(people + index) = temp;
			index++;
		}



	}

	temp = *(people + index);
	*(people + index) = *(people + end);
	*(people + end) = temp;
	return index;

}

void quicksort(stu* people, int start, int end)
{
	int index;

	if (start < end)
	{
		index = partition(people, start, end);

		quicksort(people, start, index - 1);

		quicksort(people, index + 1, end);
	}
	else
	{
		return;
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	stu* people = (stu*)malloc(n * sizeof(stu));

	for (int i = 0; i < n; i++)
	{
		scanf("%s %d %d %d", &(people + i)->name,
			&(people + i)->kor, &(people + i)->eng,
			&(people + i)->math);
	}

	quicksort(people, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		printf("%s\n", (people + i)->name);
	}
}