#include "Slist.h"

//���Է������������в�������ڵ㣩
void TestSList(){
	SLNode* L = NULL;//����һ���ṹ��L��Ϊ��
	SLPushBack(&L, 1);
	SLPushBack(&L, 2);
	SLPushBack(&L, 3);
	SLPushBack(&L, 4);
	SLPushBack(&L, 5);

}

int main(){
	TestSList();


	return 0;
}