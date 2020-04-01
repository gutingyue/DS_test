#pragma once
#include <stdio.h>
#include <Windows.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

typedef int DataType;
//不带头节点的单链表
//给出节点的定义
typedef struct SLNode 
{
	int data; //元素的内容
	struct SLNode* next; //定义同类型对象的指针
	//结构体内不能定义相同类型的成员，只能定义指针
}SLNode;    //用typedef，将struct SLNode{...}这种结构体，重命名为SLNode类型
			//若此处不加typedef，此处的SLNode意思为：struct SLNode这种类型定义出来的变量；

//动态申请节点
SLNode* BuySLNode(DataType x);

//打印链表
void PrintSList(SLNode* psl);

//尾插
void SLPushBack(SLNode** ppsl,DataType data);//C语言中使用结构体时，前面要加上struct，此处SLNode实际是重命名后的struct SLNode

//尾删
void SLPopBack(SLNode** ppsl);

//头插
void SLPushFront(SLNode** ppsl, DataType data);

//头删
void SLPopFront(SLNode** ppsl);

//单链表查找
SLNode* SLFind(SLNode* psl,DataType data);

//在pos之后插入x
void SLInterAfter(SLNode* pos, DataType x);

//删除pos之后的值
void SLEraseAfter(SLNode* pos);

//链表删除
void SLDestroy(SLNode** ppsl);


