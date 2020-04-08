#pragma once
#include <stdio.h>
#include <Windows.h>

//带头节点的双向循环链表
typedef int DataType;

typedef struct DLNode{
	struct DLNode* prev;
	struct DLNode* next;
	DataType val;
}DLNode;

//创建返回链表的头节点
DLNode* ListCreate();

//双向链表销毁
void ListDestory(DLNode** ppdl);

//双向链表打印
void ListPrint(DLNode* pdl);

//双向链表尾插
void ListPushBack(DLNode* pdl, DataType data);

//双向链表尾删
void ListPopBask(DLNode* pdl);

//双向链表头删
void ListPopFront(DLNode* pdl);

//双向链表头插
void ListPushFront(DLNode* pdl, DataType data);

//双向链表查找
DLNode* ListFind(DLNode* pdl, DataType x);

//双向链表在pos后插入data
void ListInsertNext(DLNode* pos, DataType data);
//双向链表在pos前插入data
void ListInsertPrev(DLNode* pos, DataType data);

//双向链表删除pos位置的节点
void ListErase(DLNode* pos);