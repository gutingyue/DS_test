#include "Slist.h"

//测试方法（向链表中插入五个节点）
void TestSList(){
	SLNode* L = NULL;//定义一个结构体L，为空
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