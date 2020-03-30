#pragma once

#include <stdio.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList //Sequence List :˳���
{
	SLDataType* array;//ָ��̬���ٵ�����ռ�
	int size;//��ЧԪ�ظ���   //���Ϊsize_t size;  size_t -> unsigned int �޷�������
	int capicity;//������С
}SeqList;

//˳���ĳ�ʼ��
void SeqListInit(SeqList* psl,int capicity);//Ϊpslָ��Ľṹ�忪�ٿռ䣬�Խṹ����������ֶγ�ʼ��

//˳�������
void SeqListDestory(SeqList* psl);//����ṹ��ĵ�ַ

//˳����ӡ
void SeqListPrint(SeqList* psl);

//�жϿռ��Ƿ�����������
void CheckCapacity(SeqList* psl);

//˳���β��
void SeqListPushBack(SeqList* psl, SLDataType x);

//˳���βɾ
void SeqListPopBack(SeqList* psl);

//˳���ͷ��
void SeqListPushFront(SeqList* psl, SLDataType x);

//˳���ͷɾ
void SeqListPopFront(SeqList* psl);

//˳������
int SeqListFind(SeqList* psl, SLDataType x);

