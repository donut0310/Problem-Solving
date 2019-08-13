

#include <stdio.h> 

#define MAXSIZE 51

int main() {

	int i, j, cnt, num;

	char arr[MAXSIZE];

	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{

		cnt = 0;

		scanf("%s", arr);

		for (j = 0; j < MAXSIZE; j++)
		{

			if (arr[j] == '\0')

				break;

			if (arr[j] == '(')

				cnt++;

			else if (arr[j] == ')' && cnt > 0)

				cnt--;

			else if (arr[j] == ')' && cnt <= 0) {

				cnt--;

				break;

			}

		}

		if (cnt == 0)

			printf("YES\n");

		else

			printf("NO\n");

	}

}



