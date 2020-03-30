#include "SList.h"


//申请节点，开辟空间
SLNode* BuySLNode(DataType data){
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));//申请一个SLNode大小的空间
	if (NULL == newNode){
		printf("fail to apply\n");
		assert(newNode);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//尾插
void SLPushBack(SLNode** phead, DataType data){//head是形参，如果想改变实参L的指向，就要传递二级指针（即STNode* L 的地址）
	assert(phead);//断言，判断链表是否存在，没有头指针
	SLNode* newNode = BuySLNode(data); //根据data构建新节点
	if (*phead == NULL){//判断链表内容是否为空，内无节点
		*phead = newNode;
	}
	else{
		SLNode* tail = *phead;//设置一个尾指针=L，指向头节点
		while (tail->next){
			tail = tail->next; //不能让tali++，链式结构数据存储不连续
		}
		tail->next = newNode; //将新节点连接在最后一个
	}
}

//尾删
void SLPopBack(SLNode* head){

}

//头插
void SLPushFront(SLNode* head, DataType data){

}

//头删
void SLPopFront(SLNode* head){

}

//打印链表
void PrintSList(SLNode* head){

}

