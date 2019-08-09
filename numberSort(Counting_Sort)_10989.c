#include<stdio.h>


//counting sort
//공간 복잡도가 적게 드는 장점
//배열의 초기값을 0으로 설정
//입력과 동시에 count배열에 입력값을 인덱스로하여 +1값을 저장
//반복문을 통해 인덱스로 저장된 입력값 부분까지의 값들이 
//동일한 값으로 저장되다가 입력값이 저장된 부분에서 +1
//ex 1 1 1 2 2 2 2 2 3 3 3 3 4 4 5 5 5 5 와 같이 저장
//이후 인덱스 값을 while문의 조건으로 하여 참,거짓값으로 반복문을 제어
//인덱스로 저장된 입력값의 인덱스를 출력하면 입력시 저장되었던 입력값이 
//인덱스의 위치값으로 출력되게됨

int main()
{
	int n;
	int input;
	int count[10001] = { 0, };

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		count[input]++;
	}

	for (int i = 1; i < 10001; i++)
	{
		count[i] = count[i] + count[i - 1];
	}

	for (int i = 1; i < 10001; i++)
	{
		int index = count[i] - count[i - 1];
		if (i == 1)
		{
			index = count[i];
		}

		while (index--)
		{
			printf("%d\n",i);
		}
	}
}



