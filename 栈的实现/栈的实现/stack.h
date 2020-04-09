#pragma once

typedef int Datatype;

typedef struct Stack{
	Datatype* array; //数组空间
	int size;     //有效数据
	int capacity;//容量
}Stack;

//初始化栈
void StackInit(Stack* ps);

//入栈
void StackPush(Stack* ps, Datatype data);
//出栈
void StackPop(Stack* ps);

//获取栈顶元素
Datatype StackTop(Stack* ps);

//获取栈中有效元素个数
int StackSize(Stack* ps);

//检验栈是否为空
int StackEmpty(Stack* ps);
