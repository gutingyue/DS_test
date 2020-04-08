#include "DListNode.h"
#include <malloc.h>
#include <assert.h>

DLNode* BuyNode(DataType val){
	DLNode* newNode = (DLNode*)malloc(sizeof(DataType));

	if (newNode == NULL){
		assert(0);//申请空间失败
		return NULL;
	}

	newNode->val = val;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//创建返回链表的头节点
DLNode* ListCreate(){

	DLNode* head = BuyNode(0);
	head->next = head;
	head->prev = head;

	return head;
}

//双向链表销毁
void ListDestory(DLNode** ppdl){
	if (*ppdl == NULL){
		assert(0);
		return;
	}

	DLNode* cur = (*ppdl)->next;

	while (cur != *ppdl){
		(*ppdl)->next = cur->next;
		free(cur);
		cur = (*ppdl)->next;
	}
	free(*ppdl);//删除头节点
	*ppdl = NULL;
}

//双向链表打印
void ListPrint(DLNode* pdl){
	if (pdl == NULL){
		assert(0);
		return;
	}
	DLNode* pos = pdl;
	while (pos->next != pdl){
		pos = pos->next;
		printf("%d ", pos->val);
	}
	printf("\n");
}

//双向链表尾插
void ListPushBack(DLNode* pdl, DataType data){
	if (pdl == NULL){
		assert(0);//assert是调试宏，只在debug模式下存在，在release模式下被删除
		return;
	}
	DLNode* newNode = BuyNode(data);
	//将新节点连接到原链中
	newNode->prev = pdl->prev;
	newNode->next = pdl;

	//改变原链相应链接指针
	pdl->prev->next = newNode;
	pdl->prev = newNode;
}

//双向链表尾删
void ListPopBask(DLNode* pdl){
	if (pdl == NULL){ //链表不存在
		assert(0);
		return;
	}
	if (pdl->prev == pdl){ //空链表（只有一个头节点）
		return;
	}
	//先链接，后释放节点
	DLNode* pos = pdl->prev;
	pos->prev->next = pdl;
	pdl->prev = pos->prev;

	free(pos);
}

//双向链表头删
void ListPopFront(DLNode* pdl){
	if (pdl == NULL){
		assert(0);
		return;
	}

	DLNode* cur = pdl->next;
	pdl->next = cur->next;
	cur->next->prev = pdl;
	free(cur);
}

//双向链表头插
void ListPushFront(DLNode* pdl, DataType data){
	if (pdl == NULL){
		assert(0);
		return;
	}
	DLNode* newNode = BuyNode(data);
	newNode->prev = pdl;
	newNode->next = pdl->next;

	pdl->next = newNode;
	newNode->next->prev = newNode;
}

//双向链表查找
DLNode* ListFind(DLNode* pdl, DataType x){
	if (pdl == NULL){
		assert(0);
		return NULL;
	}

	DLNode* pos = pdl->next;
	while (pos != pdl){
		if (pos->val == x){
			return pos;
		}
		pos = pos->next;
	}
	return NULL;
}

//双向链表在pos后插入data
void ListInsertNext(DLNode* pos, DataType data){
	if (pos == NULL){
		assert(0);
		return;
	}

	DLNode* newNode = BuyNode(data);
	//newNode与原链链接
	newNode->prev = pos;
	newNode->next = pos->next;

	//原链对应指针重新指向newNode
	newNode->prev->next = newNode;
	newNode->next->prev = newNode;
}

//双向链表在pos前插入data
void ListInsertPrev(DLNode* pos, DataType data){
	if (pos == NULL){
		assert(0);
		return;
	}

	DLNode* newNode = BuyNode(data);

	newNode->prev = pos->prev;
	newNode->next = pos;
	newNode->prev->next = newNode;
	newNode->next->prev = newNode;
}

//双向链表删除pos位置的节点
void ListErase(DLNode* pos){
	if (pos == NULL){
		assert(0);
		return;
	}

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;

	free(pos);
}