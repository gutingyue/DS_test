#include "DListNode.h"

void Test1(){
	DLNode * L1 = ListCreate();
	ListPushBack(L1, 1);
	ListPushBack(L1, 2);
	ListPushBack(L1, 3);
	ListPushBack(L1, 4);
	ListPushBack(L1, 5);
	ListPrint(L1);

	DLNode* pos=ListFind(L1, 2);//在链表里找到2
	ListPrint(pos);

	ListInsertNext(pos, -2);//在pos之后插入-2
	ListPrint(L1);
	ListInsertPrev(pos, -1);
	ListPrint(L1);

	printf("给L1头插0：");
	ListPushFront(L1, 0);
	ListPrint(L1);

	ListDestory(&L1);
}


int main(){
	Test1();


	system("pause");
	return 0;
}