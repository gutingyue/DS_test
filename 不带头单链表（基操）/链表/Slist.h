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

//��̬����ڵ�
SLNode* BuySLNode(DataType x);

//��ӡ����
void PrintSList(SLNode* psl);

//β��
void SLPushBack(SLNode** ppsl,DataType data);//C������ʹ�ýṹ��ʱ��ǰ��Ҫ����struct���˴�SLNodeʵ�������������struct SLNode

//βɾ
void SLPopBack(SLNode** ppsl);

//ͷ��
void SLPushFront(SLNode** ppsl, DataType data);

//ͷɾ
void SLPopFront(SLNode** ppsl);

//���������
SLNode* SLFind(SLNode* psl,DataType data);

//��pos֮�����x
void SLInterAfter(SLNode* pos, DataType x);

//ɾ��pos֮���ֵ
void SLEraseAfter(SLNode* pos);

//����ɾ��
void SLDestroy(SLNode** ppsl);


