#include "stack.h"
#include <assert.h>
#include <malloc.h>
#include<stdio.h>
#include<Windows.h>

//栈扩容
void CheckCapacity(Stack* ps){
	if (ps->size >= ps->capacity){
		//申请新空间
		Datatype* temp = (Datatype*)malloc(sizeof(Datatype)*(ps->capacity) * 2);
		if (temp){
			//拷贝元素
			//memcpy(temp,ps->array,sizeof(Datatype)*(ps->capacity);
			for (int i = 0; i < ps->size;i++){
				temp[i] = ps->array[i];
			}

			//释放旧空间
			free(ps->array);

			ps->array = temp;
		}
	}
}

//初始化栈
void StackInit(Stack* ps){
	assert(ps);
	ps->array = (Datatype*)malloc(sizeof(Datatype)* 5);//初始容量为5
	ps->capacity = 5;
	ps->size = 0;
}

//入栈
void StackPush(Stack* ps, Datatype data){
	assert(ps);

	CheckCapacity(ps);//扩容函数

	ps->array[ps->size] = data;
	ps->size++;
}

//出栈
void StackPop(Stack* ps){
	assert(ps);

	if (StackEmpty(ps))//检测栈是否为空
		return;

	ps->size--;
}

//获取栈顶元素
Datatype StackTop(Stack* ps){
	assert(ps);

	return ps->array[ps->size - 1];
}

//获取栈中有效元素个数
int StackSize(Stack* ps){
	assert(ps);
	return ps->size;
}

//检验栈是否为空,为空返回非零
int StackEmpty(Stack* ps){
	assert(ps);
	
	return ps->size == 0;
}

void StackDestroy(Stack* ps){
	assert(ps);

	free(ps->array);
	ps->capacity = 0;
	ps->size = 0;
}