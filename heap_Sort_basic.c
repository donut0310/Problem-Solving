//#include<stdio.h>
//
//int main()
//{
//	int number = 9;
//	int heap[9] = { 1,5,2,3,7,9,6,10,13 };
//
//	//���� ��ü Ʈ�������� �ִ��� ������ ����
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
//	//�迭ũ�� �ٿ����� �� ����
//	for (int i = number - 1; i >= 0; i--)
//	{
//		//��Ʈ����� ���� �迭 ������ ��尪�� �ٲ��ش�
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
//			//�ڽĳ�峢�� ũ�� ��, cnt ��������
//			if (heap[cnt] < heap[cnt + 1] && cnt < i - 1)
//			{
//				cnt++; //�����ڽ��� �������ڽĺ��� ���� ���
//				//�� ū���� ������ �ڽ��� ����Ű������ cnt++
//			}
//			//�θ���� ��
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