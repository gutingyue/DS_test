#pragma once

#include <stdio.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList //Sequence List :顺序表
{
	SLDataType* array;//指向动态开辟的数组空间
	int size;//有效元素个数   //或改为size_t size;  size_t -> unsigned int 无符号整型
	int capicity;//容量大小
}SeqList;

//顺序表的初始化
void SeqListInit(SeqList* psl,int capicity);//为psl指向的结构体开辟空间，对结构体变量各个字段初始化

//顺序表销毁
void SeqListDestory(SeqList* psl);//给入结构体的地址

//顺序表打印
void SeqListPrint(SeqList* psl);

//判断空间是否已满，增容
void CheckCapacity(SeqList* psl);

//顺序表尾插
void SeqListPushBack(SeqList* psl, SLDataType x);

//顺序表尾删
void SeqListPopBack(SeqList* psl);

//顺序表头插
void SeqListPushFront(SeqList* psl, SLDataType x);

//顺序表头删
void SeqListPopFront(SeqList* psl);

//顺序表查找
int SeqListFind(SeqList* psl, SLDataType x);

