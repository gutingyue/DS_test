#include "SList.h"


//����ڵ㣬���ٿռ�
SLNode* BuySLNode(DataType data){
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));//����һ��SLNode��С�Ŀռ�
	if (NULL == newNode){
		printf("fail to apply\n");
		assert(newNode);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//β��
void SLPushBack(SLNode** phead, DataType data){//head���βΣ������ı�ʵ��L��ָ�򣬾�Ҫ���ݶ���ָ�루��STNode* L �ĵ�ַ��
	assert(phead);//���ԣ��ж������Ƿ���ڣ�û��ͷָ��
	SLNode* newNode = BuySLNode(data); //����data�����½ڵ�
	if (*phead == NULL){//�ж����������Ƿ�Ϊ�գ����޽ڵ�
		*phead = newNode;
	}
	else{
		SLNode* tail = *phead;//����һ��βָ��=L��ָ��ͷ�ڵ�
		while (tail->next){
			tail = tail->next; //������tali++����ʽ�ṹ���ݴ洢������
		}
		tail->next = newNode; //���½ڵ����������һ��
	}
}

//βɾ
void SLPopBack(SLNode* head){

}

//ͷ��
void SLPushFront(SLNode* head, DataType data){

}

//ͷɾ
void SLPopFront(SLNode* head){

}

//��ӡ����
void PrintSList(SLNode* head){

}

