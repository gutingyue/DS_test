#include "DListNode.h"
#include <malloc.h>
#include <assert.h>

DLNode* BuyNode(DataType val){
	DLNode* newNode = (DLNode*)malloc(sizeof(DataType));

	if (newNode == NULL){
		assert(0);//����ռ�ʧ��
		return NULL;
	}

	newNode->val = val;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//�������������ͷ�ڵ�
DLNode* ListCreate(){

	DLNode* head = BuyNode(0);
	head->next = head;
	head->prev = head;

	return head;
}

//˫����������
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
	free(*ppdl);//ɾ��ͷ�ڵ�
	*ppdl = NULL;
}

//˫�������ӡ
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

//˫������β��
void ListPushBack(DLNode* pdl, DataType data){
	if (pdl == NULL){
		assert(0);//assert�ǵ��Ժֻ꣬��debugģʽ�´��ڣ���releaseģʽ�±�ɾ��
		return;
	}
	DLNode* newNode = BuyNode(data);
	//���½ڵ����ӵ�ԭ����
	newNode->prev = pdl->prev;
	newNode->next = pdl;

	//�ı�ԭ����Ӧ����ָ��
	pdl->prev->next = newNode;
	pdl->prev = newNode;
}

//˫������βɾ
void ListPopBask(DLNode* pdl){
	if (pdl == NULL){ //��������
		assert(0);
		return;
	}
	if (pdl->prev == pdl){ //������ֻ��һ��ͷ�ڵ㣩
		return;
	}
	//�����ӣ����ͷŽڵ�
	DLNode* pos = pdl->prev;
	pos->prev->next = pdl;
	pdl->prev = pos->prev;

	free(pos);
}

//˫������ͷɾ
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

//˫������ͷ��
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

//˫���������
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

//˫��������pos�����data
void ListInsertNext(DLNode* pos, DataType data){
	if (pos == NULL){
		assert(0);
		return;
	}

	DLNode* newNode = BuyNode(data);
	//newNode��ԭ������
	newNode->prev = pos;
	newNode->next = pos->next;

	//ԭ����Ӧָ������ָ��newNode
	newNode->prev->next = newNode;
	newNode->next->prev = newNode;
}

//˫��������posǰ����data
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

//˫������ɾ��posλ�õĽڵ�
void ListErase(DLNode* pos){
	if (pos == NULL){
		assert(0);
		return;
	}

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;

	free(pos);
}