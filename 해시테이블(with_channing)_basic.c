//#include<stdio.h>
//#include<stdlib.h>
//
//struct bucket* hashTable = NULL;
//int SIZE = 10; //해쉬테이블의 버켓 사이즈
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
////노드 생성
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
////해시테이블의 버켓으로 넣기 위해 조건을 주는 해시함수
//int hashFunction(int key)
//{
//	return key % SIZE;
//}
//
////해시테이블에 노드 추가
//void insert(int key, int value)
//{
//	int hashIndex = hashFunction(key); //해시함수를 통해 인덱스를 받아온다
//	struct Node* newNode = createNode(key, value); //해시테이블로 넣기위한 노드생성
//	
//	//아무 노드가 없는 경우
//	if (hashTable[hashIndex].count == 0)
//	{
//		hashTable[hashIndex].count = 1;
//		hashTable[hashIndex].head = newNode;
//	}
//
//	//내가 넣고자 하는 인덱스에 이미 값이 있는 경우
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
//	horse = hashTable[hashIndex].head; //해시테이블의 헤드를 가리킴
//	
//	//헤드가 없을때
//	if (horse == NULL)
//	{
//		printf("\nno key found\n");
//		return;
//	}
//	while (horse != NULL)
//	{
//		//찾았을때 헤드인지 아닌지 판별해줘야함
//		if (horse->key == key)
//		{
//			//헤드일때 헤드를 옮겨줘야함
//			if (horse == hashTable[hashIndex].head)
//			{
//				hashTable[hashIndex].head = horse->next;
//			}
//			//헤드가 아니라면? 이전 노드의 넥스트를 현재노드의 넥스트로 연결해줘야함
//			//단일 연결리스트이기에 prev가 없음
//			//추가로 노드가 필요함 (traceNode)
//			else
//			{
//				traceNode->next = horse->next;
//
//			}
//
//			//지우는 작업
//			//count를 내려주는 작업
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
//// 키값에 따른 버켓에 노드를 찾았을때
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
//		//찾았을때
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
////해시의 현재상태를 알려주는 함수
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
//		//버켓안의 여러 노드가있을때 조사해야함
//		//for루프로 각 버켓의 count 값을 기준으로 돌려도됨
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
