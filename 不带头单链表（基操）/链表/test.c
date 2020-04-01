#include "Slist.h"



int main(){
	SLNode* psl = NULL;//定义一个结构体sl的指针，为空

	//尾插五个节点
	SLPushBack(&psl, 1);//因为会改变psl的指向，所以传入的是psl的地址（二级指针）
	SLPushBack(&psl, 2);
	SLPushBack(&psl, 3);
	SLPushBack(&psl, 4);
	SLPushBack(&psl, 5);

	PrintSList(psl);

	printf("尾删：");
	SLPopBack(&psl);
	PrintSList(psl);

	printf("头插0：");
	SLPushFront(&psl, 0);
	PrintSList(psl);

	printf("头删：");
	SLPopFront(&psl);
	//SLPopFront(&psl);
	//SLPopFront(&psl);
	//SLPopFront(&psl);
	//SLPopFront(&psl);
	//SLPopFront(&psl);
	//SLPopFront(&psl);
	PrintSList(psl);

	SLNode* pos = SLFind(psl, 3);
	printf("\nfind pos==3:");
	PrintSList(pos);
	//printf("\nfind 8:"); //注释快捷键 Ctrl + K + C
	//pos = slfind(psl, 8);
	//printslist(pos);

	printf("\n在pos后插入3：");
	SLInterAfter(pos, 3);//此时pos指向3，在其后面插入3
	PrintSList(psl); // 1 -> 2 -> 3 -> 3 -> 4 -> NULL

	printf("\n删除pos之后的节点：");
	SLEraseAfter(pos);
	PrintSList(psl);

	printf("删除链表：");
	SLDestroy(&psl);
	PrintSList(psl);

	system("pause");
	return 0;
}