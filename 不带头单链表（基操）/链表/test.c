#include "Slist.h"



int main(){
	SLNode* psl = NULL;//����һ���ṹ��sl��ָ�룬Ϊ��

	//β������ڵ�
	SLPushBack(&psl, 1);//��Ϊ��ı�psl��ָ�����Դ������psl�ĵ�ַ������ָ�룩
	SLPushBack(&psl, 2);
	SLPushBack(&psl, 3);
	SLPushBack(&psl, 4);
	SLPushBack(&psl, 5);

	PrintSList(psl);

	printf("βɾ��");
	SLPopBack(&psl);
	PrintSList(psl);

	printf("ͷ��0��");
	SLPushFront(&psl, 0);
	PrintSList(psl);

	printf("ͷɾ��");
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
	//printf("\nfind 8:"); //ע�Ϳ�ݼ� Ctrl + K + C
	//pos = slfind(psl, 8);
	//printslist(pos);

	printf("\n��pos�����3��");
	SLInterAfter(pos, 3);//��ʱposָ��3������������3
	PrintSList(psl); // 1 -> 2 -> 3 -> 3 -> 4 -> NULL

	printf("\nɾ��pos֮��Ľڵ㣺");
	SLEraseAfter(pos);
	PrintSList(psl);

	printf("ɾ������");
	SLDestroy(&psl);
	PrintSList(psl);

	system("pause");
	return 0;
}