//#include<stdio.h>
//#include<stdlib.h>
//
//struct bucket* hashTable = NULL;
//int SIZE = 10; //�ؽ����̺��� ���� ������
//
//struct Node {
//	int key;
//	int value;
//	struct Node* next;
//};
//
//struct bucket {
//	struct Node* head;
//	int count;
//};
//
////��� ����
//struct Node* createNode(int key, int value)
//{
//	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//	newNode->key = key;
//	newNode->value = value;
//	newNode->next = NULL;
//	
//	return newNode;
//}
//
////�ؽ����̺��� �������� �ֱ� ���� ������ �ִ� �ؽ��Լ�
//int hashFunction(int key)
//{
//	return key % SIZE;
//}
//
////�ؽ����̺� ��� �߰�
//void insert(int key, int value)
//{
//	int hashIndex = hashFunction(key); //�ؽ��Լ��� ���� �ε����� �޾ƿ´�
//	struct Node* newNode = createNode(key, value); //�ؽ����̺�� �ֱ����� ������
//	
//	//�ƹ� ��尡 ���� ���
//	if (hashTable[hashIndex].count == 0)
//	{
//		hashTable[hashIndex].count = 1;
//		hashTable[hashIndex].head = newNode;
//	}
//
//	//���� �ְ��� �ϴ� �ε����� �̹� ���� �ִ� ���
//	else
//	{
//		newNode->next = hashTable[hashIndex].head;
//		hashTable[hashIndex].head = newNode;
//		hashTable[hashIndex].count++;
//	}
//	return;
//}
//
//void removeNode(int key)
//{
//	int hashIndex = hashFunction(key);
//	 
//	struct Node* horse;
//	struct Node* traceNode;
//	horse = hashTable[hashIndex].head; //�ؽ����̺��� ��带 ����Ŵ
//	
//	//��尡 ������
//	if (horse == NULL)
//	{
//		printf("\nno key found\n");
//		return;
//	}
//	while (horse != NULL)
//	{
//		//ã������ ������� �ƴ��� �Ǻ��������
//		if (horse->key == key)
//		{
//			//����϶� ��带 �Ű������
//			if (horse == hashTable[hashIndex].head)
//			{
//				hashTable[hashIndex].head = horse->next;
//			}
//			//��尡 �ƴ϶��? ���� ����� �ؽ�Ʈ�� �������� �ؽ�Ʈ�� �����������
//			//���� ���Ḯ��Ʈ�̱⿡ prev�� ����
//			//�߰��� ��尡 �ʿ��� (traceNode)
//			else
//			{
//				traceNode->next = horse->next;
//
//			}
//
//			//����� �۾�
//			//count�� �����ִ� �۾�
//			hashTable[hashIndex].count--;
//			free(horse);
//			return;
//		}
//		traceNode = horse;
//		horse = horse->next;
//
//	}
//	printf("\nno key found");
//	return;
//}
//
//// Ű���� ���� ���Ͽ� ��带 ã������
//void search(int key)
//{
//	int hashIndex = hashFunction(key);
//	struct Node* horse = hashTable[hashIndex].head;
//
//	if (horse == NULL)
//	{
//		printf("no key found\n");
//		printf("--------------------------------\n");
//		return;
//	}
//
//	while (horse != NULL)
//	{
//		//ã������
//		if (horse->key == key)
//		{
//			printf("\nkey found -> key = [%d] value = [%d] \n", horse->key, horse->value);
//			printf("--------------------------------\n");
//			return;
//		}
//		horse = horse->next;
//	}
//
//}
//
////�ؽ��� ������¸� �˷��ִ� �Լ�
//void display()
//{
//	struct Node* horse;
//	int i = 0;
//
//	for (i = 0; i < SIZE; i++)
//	{
//		horse = hashTable[i].head;
//		printf("Bucket[%d] : ", i);
//
//		//���Ͼ��� ���� ��尡������ �����ؾ���
//		//for������ �� ������ count ���� �������� ��������
//		while (horse != NULL)
//		{
//			printf("(key : %d, val : %d) -> ", horse->key, horse->value);
//			horse = horse->next;
//		}
//		printf("\n");
//	}
//	printf("\n-------end of display-----------\n");
//	return;
//}
//
//int main()
//{
//	hashTable = (struct bucket*)malloc(SIZE * sizeof(struct bucket));
//	for (int i = 0; i < SIZE; i++)
//	{
//		hashTable[i].count = 0;
//		hashTable[i].head = NULL;
//	}
//	insert(0, 1);
//	insert(1, 10);
//	insert(11, 90);
//	insert(21, 64);
//	insert(31, 23);
//	insert(6, 25);
//	insert(97, 4);
//
//	display();
//	search(6);
//	search(85);
//	removeNode(31);
//	removeNode(11);
//
//	display();
//}
