#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int DataType;

//�����еĽڵ�ṹ
typedef struct QueueNode{
	DataType val;
	struct QNode* next;
}QNode;

//���нṹ
typedef struct Queue{
	struct QNode* front; //ͷָ��
	struct QNode* rear; //βָ��
	int size;
}Queue;

//��ʼ������
void QueueInit(Queue* q);

//���д�ӡ
void QueuePrint(Queue* q);

//��� ����β�룩
void QueuePush(Queue* q, DataType data);

//���� ����ͷ����
void QueuePop(Queue* q);

//��ȡ��ͷԪ��
DataType QueueFront(Queue* q);

//��ȡ��βԪ��
DataType QueueBack(Queue* q);

//��ȡ������ЧԪ�ظ���
int QueueSize(Queue* q);

//��������Ƿ�Ϊ�գ��ǿշ���0
int QueueEmpty(Queue* q);

//���ٶ���
void QueueDestroy(Queue* q);