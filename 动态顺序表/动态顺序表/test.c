#include "SeqList.h"
#include <Windows.h>

int main(){
	SeqList sl;
	SeqListInit(&sl, 2);
	printf("����˳���");
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	
	SeqListPrint(&sl);

	printf("ͷ��0��");
	SeqListPushFront(&sl, 0);
	SeqListPrint(&sl);

	printf("ͷɾ��");
	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListFind(&sl, 3);//�ҵ������±�

	SeqListDestory(&sl);


	system("pause");
	return 0;
}