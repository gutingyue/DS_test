#include "SList.h"


//申请节点，开辟空间
SLNode* BuySLNode(DataType data){
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));//申请一个SLNode大小的空间
	if (NULL == newNode){
		printf("fail to apply\n");//申请失败
		assert(newNode);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}


//打印链表
void PrintSList(SLNode* psl){
	SLNode* cur = psl;
	while (cur){
		printf("%d --> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


//尾插
void SLPushBack(SLNode** ppsl, DataType data){//head是形参，如果想改变实参L的指向，就要传递二级指针（即STNode* L 的地址）
	assert(ppsl);//断言，判断链表是否存在，没有头指针

	SLNode* newNode = BuySLNode(data); //根据data构建新节点

	if (*ppsl == NULL){//判断链表内容是否为空，内无节点
		*ppsl = newNode;
	}
	else{
		SLNode* tail = *ppsl;//设置一个尾指针=L，指向头节点
		while (tail->next){
			tail = tail->next; //不能让tali++，链式结构数据存储不连续
		}
		tail->next = newNode; //将新节点连接在最后一个
	}
}


//尾删
void SLPopBack(SLNode** ppsl){
	assert(ppsl);

	if (*ppsl == NULL){
		return;
	}
	else if ((*ppsl)->next==NULL){ //链中只有一个节点
		free((*ppsl)->next);
		*ppsl = NULL;
	}
	else {
		SLNode* cur = *ppsl;
		SLNode* prev = cur;
		while (cur->next){
			prev = cur; //最终cur指向最后一个节点，prev指向倒数第二个节点
			cur = cur->next;
		}
		prev->next = cur->next;//将倒数第二个节点的next指向NULL
		free(cur);//释放最后一个节点
	}
}


//头插
void SLPushFront(SLNode** ppsl, DataType data){
	assert(ppsl);//assert没有触发，说明链表存在（不等于链表为空）

	SLNode* newNode=BuySLNode(data);

	newNode->next = *ppsl;
	*ppsl=newNode;
}


//头删
void SLPopFront(SLNode** ppsl){
	assert(ppsl);

	if (*ppsl == NULL){
		return;
	}
	SLNode* cur = *ppsl;
	*ppsl = (*ppsl)->next;
	free(cur);
}


//单链表查找
SLNode* SLFind(SLNode* psl, DataType data){
	assert(psl);

	SLNode* cur = psl;

	while (cur){
		if (cur->data == data){
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


//在pos之后插入x
void SLInterAfter(SLNode* pos, DataType x){
	SLNode* newNode=BuySLNode(x);

	if (pos == NULL){
		pos = newNode;
	}
	else{
		newNode->next = pos->next;
		pos->next = newNode;
	}
}


//删除pos之后的值
void SLEraseAfter(SLNode* pos){
	if (pos == NULL){
		return;
	}
	else{
		SLNode* cur = pos->next;
		pos->next = cur->next;
		free(cur);
	}
	
}