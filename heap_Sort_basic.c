//#include<stdio.h>
//
//int main()
//{
//	int number = 9;
//	int heap[9] = { 1,5,2,3,7,9,6,10,13 };
//
//	//먼저 전체 트리구조를 최대힙 구조로 변경
//	for (int i = 1; i < number; i++)
//	{
//		int cnt = i;
//
//		while (cnt!=0)
//		{
//			int root = (cnt - 1) / 2;
//
//			if (heap[root] < heap[cnt])
//			{
//				int temp = heap[root];
//				heap[root] = heap[cnt];
//				heap[cnt] = temp;
//			}
//			cnt = root;
//		}
//	}
//	for (int i = 0; i < number; i++)
//	{
//		printf("%d ", heap[i]);
//	}
//	printf("\n");
//
//	//배열크기 줄여가며 힙 구성
//	for (int i = number - 1; i >= 0; i--)
//	{
//		//루트노드의 값을 배열 마지막 노드값과 바꿔준다
//		int temp = heap[0];
//		heap[0] = heap[i];
//		heap[i] = temp;
//		
//		int root = 0;
//		int cnt = 1;
//		
//		while (cnt < i)
//		{
//			cnt = 2 * root + 1;
//			//자식노드끼리 크기 비교, cnt 범위설정
//			if (heap[cnt] < heap[cnt + 1] && cnt < i - 1)
//			{
//				cnt++; //왼쪽자식이 오른쪽자식보다 작을 경우
//				//더 큰값인 오른쪽 자식을 가리키기위해 cnt++
//			}
//			//부모노드와 비교
//			if (heap[root] < heap[cnt] && cnt < i)
//			{
//				int temp = heap[root];
//				heap[root] = heap[cnt];
//				heap[cnt] = temp;
//			}
//			root = cnt;
//		}
//	}
//	for (int i = 0; i < number; i++)
//	{
//		printf("%d ", heap[i]);
//	}
//
//	
//} 