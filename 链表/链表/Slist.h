#pragma once
#include <stdio.h>
#include <Windows.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

typedef int DataType;
//����ͷ�ڵ�ĵ�����
//�����ڵ�Ķ���
typedef struct SLNode 
{
	int data; //Ԫ�ص�����
	struct SLNode* next; //����ͬ���Ͷ����ָ��
	//�ṹ���ڲ��ܶ�����ͬ���͵ĳ�Ա��ֻ�ܶ���ָ��
}SLNode;    //��typedef����struct SLNode{...}���ֽṹ�壬������ΪSLNode����
			//���˴�����typedef���˴���SLNode��˼Ϊ��struct SLNode�������Ͷ�������ı�����

//β��
void SLPushBack(SLNode* head,DataType data);//C������ʹ�ýṹ��ʱ��ǰ��Ҫ����struct���˴�SLNodeʵ�������������struct SLNode
//βɾ
void SLPopBack(SLNode* head);

//ͷ��
void SLPushFront(SLNode* head, DataType data);
//ͷɾ
void SLPopFront(SLNode* head);

//��ӡ����
void PrintSList(SLNode* head);

