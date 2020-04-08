#pragma once
#include <stdio.h>
#include <Windows.h>

//��ͷ�ڵ��˫��ѭ������
typedef int DataType;

typedef struct DLNode{
	struct DLNode* prev;
	struct DLNode* next;
	DataType val;
}DLNode;

//�������������ͷ�ڵ�
DLNode* ListCreate();

//˫����������
void ListDestory(DLNode** ppdl);

//˫�������ӡ
void ListPrint(DLNode* pdl);

//˫������β��
void ListPushBack(DLNode* pdl, DataType data);

//˫������βɾ
void ListPopBask(DLNode* pdl);

//˫������ͷɾ
void ListPopFront(DLNode* pdl);

//˫������ͷ��
void ListPushFront(DLNode* pdl, DataType data);

//˫���������
DLNode* ListFind(DLNode* pdl, DataType x);

//˫��������pos�����data
void ListInsertNext(DLNode* pos, DataType data);
//˫��������posǰ����data
void ListInsertPrev(DLNode* pos, DataType data);

//˫������ɾ��posλ�õĽڵ�
void ListErase(DLNode* pos);