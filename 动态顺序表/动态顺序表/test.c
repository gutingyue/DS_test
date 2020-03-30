#include "SeqList.h"
#include <Windows.h>

int main(){
	SeqList sl;
	SeqListInit(&sl, 2);
	printf("建立顺序表：");
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	
	SeqListPrint(&sl);

	printf("头插0：");
	SeqListPushFront(&sl, 0);
	SeqListPrint(&sl);

	printf("头删：");
	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListFind(&sl, 3);//找到返回下标

	SeqListDestory(&sl);


	system("pause");
	return 0;
}