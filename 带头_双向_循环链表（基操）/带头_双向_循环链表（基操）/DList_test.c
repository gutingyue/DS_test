#include "DListNode.h"

void Test1(){
	DLNode * L1 = ListCreate();
	ListPushBack(L1, 1);
	ListPushBack(L1, 2);
	ListPushBack(L1, 3);
	ListPushBack(L1, 4);
	ListPushBack(L1, 5);
	ListPrint(L1);

	DLNode* pos=ListFind(L1, 2);//���������ҵ�2
	ListPrint(pos);

	ListInsertNext(pos, -2);//��pos֮�����-2
	ListPrint(L1);
	ListInsertPrev(pos, -1);
	ListPrint(L1);

	printf("��L1ͷ��0��");
	ListPushFront(L1, 0);
	ListPrint(L1);

	ListDestory(&L1);
}


int main(){
	Test1();


	system("pause");
	return 0;
}