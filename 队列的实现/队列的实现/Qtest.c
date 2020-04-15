#include "Queue.h"

#include<stdio.h>
#include<Windows.h>

typedef struct myStack{ //两个队列实现栈
	Queue q1;
	Queue q2;
}myStack;

//栈的创建(双队列）
myStack* StackCreat(){
	myStack* ms = (myStack*)malloc(sizeof(myStack));

	QueueInit(&ms->q1);
	QueueInit(&ms->q2);

	return ms;
}

//入栈（双队列）
void StackPush(myStack* ms,DataType data){
	if (ms == NULL){
		return;
	}
	if (!QueueEmpty(&ms->q1)){
		QueuePush(&ms->q1, data);
	}
	else{
		QueuePush(&ms->q2, data);
	}
}

//出栈（双队列）
DataType StackPop(myStack* ms){
	if (ms == NULL){
		return;
	}
	DataType ret = 0;

	if (!QueueEmpty(&ms->q1)){

		//将q1中n-1个元素搬移到q2
		while (QueueSize(&ms->q1)>1){
			QueuePush(&ms->q1, QueueFront(&ms->q1));
			QueuePop(&ms->q1);
		}
		ret = QueueFront(&ms->q1);
		QueuePop(&ms->q1);
	}
	else{
		while (QueueSize(&ms->q2)>1){
			QueuePush(&ms->q2, QueueFront(&ms->q2));
			QueuePop(&ms->q2);
		}
		ret = QueueFront(&ms->q2);
		QueuePop(&ms->q2);
	}

	return ret;	
}

//获取栈顶元素（双队列）
DataType StackTop(myStack* ms){
	if (ms == NULL){
		return NULL;
	}
	if (!QueueEmpty(&ms->q1)){
		return QueueBack(&ms->q1);
	}
	else{
		return QueueBack(&ms->q2);
	}
}

//用队列模拟实现栈
void Stacktest(){
	

	

}

int main(){

	Queue q;
	QueueInit(&q);

	QueuePush(&q, 0);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);

	QueuePrint(&q);


	system("pause");
	return 0;
}