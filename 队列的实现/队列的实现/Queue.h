#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int DataType;

//队列中的节点结构
typedef struct QueueNode{
	DataType val;
	struct QNode* next;
}QNode;

//队列结构
typedef struct Queue{
	struct QNode* front; //头指针
	struct QNode* rear; //尾指针
	int size;
}Queue;

//初始化队列
void QueueInit(Queue* q);

//队列打印
void QueuePrint(Queue* q);

//入队 （队尾入）
void QueuePush(Queue* q, DataType data);

//出队 （队头出）
void QueuePop(Queue* q);

//获取队头元素
DataType QueueFront(Queue* q);

//获取队尾元素
DataType QueueBack(Queue* q);

//获取队列有效元素个数
int QueueSize(Queue* q);

//检验队列是否为空，非空返回0
int QueueEmpty(Queue* q);

//销毁队列
void QueueDestroy(Queue* q);