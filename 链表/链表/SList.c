#include "SList.h"


//����ڵ㣬���ٿռ�
SLNode* BuySLNode(DataType data){
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));//����һ��SLNode��С�Ŀռ�
	if (NULL == newNode){
		printf("fail to apply\n");//����ʧ��
		assert(newNode);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}


//��ӡ����
void PrintSList(SLNode* psl){
	SLNode* cur = psl;
	while (cur){
		printf("%d --> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


//β��
void SLPushBack(SLNode** ppsl, DataType data){//head���βΣ������ı�ʵ��L��ָ�򣬾�Ҫ���ݶ���ָ�루��STNode* L �ĵ�ַ��
	assert(ppsl);//���ԣ��ж������Ƿ���ڣ�û��ͷָ��

	SLNode* newNode = BuySLNode(data); //����data�����½ڵ�

	if (*ppsl == NULL){//�ж����������Ƿ�Ϊ�գ����޽ڵ�
		*ppsl = newNode;
	}
	else{
		SLNode* tail = *ppsl;//����һ��βָ��=L��ָ��ͷ�ڵ�
		while (tail->next){
			tail = tail->next; //������tali++����ʽ�ṹ���ݴ洢������
		}
		tail->next = newNode; //���½ڵ����������һ��
	}
}


//βɾ
void SLPopBack(SLNode** ppsl){
	assert(ppsl);

	if (*ppsl == NULL){
		return;
	}
	else if ((*ppsl)->next==NULL){ //����ֻ��һ���ڵ�
		free((*ppsl)->next);
		*ppsl = NULL;
	}
	else {
		SLNode* cur = *ppsl;
		SLNode* prev = cur;
		while (cur->next){
			prev = cur; //����curָ�����һ���ڵ㣬prevָ�����ڶ����ڵ�
			cur = cur->next;
		}
		prev->next = cur->next;//�������ڶ����ڵ��nextָ��NULL
		free(cur);//�ͷ����һ���ڵ�
	}
}


//ͷ��
void SLPushFront(SLNode** ppsl, DataType data){
	assert(ppsl);

	SLNode* newNode=BuySLNode(data);

	newNode->next = *ppsl;
	*ppsl=newNode;
}


//ͷɾ
void SLPopFront(SLNode** ppsl);


//���������
SLNode* SLFind(SLNode* psl,DataType data);


//��pos֮�����x
void SLInterAfter(SLNode* pos, DataType x);


//ɾ��pos֮���ֵ
void SLEraseAfter(SLNode* pos);