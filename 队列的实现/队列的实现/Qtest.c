#include "Queue.h"

#include<stdio.h>
#include<Windows.h>

typedef struct myStack{ //��������ʵ��ջ
	Queue q1;
	Queue q2;
}myStack;

//ջ�Ĵ���(˫���У�
myStack* StackCreat(){
	myStack* ms = (myStack*)malloc(sizeof(myStack));

	QueueInit(&ms->q1);
	QueueInit(&ms->q2);

	return ms;
}

//��ջ��˫���У�
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

//��ջ��˫���У�
DataType StackPop(myStack* ms){
	if (ms == NULL){
		return;
	}
	DataType ret = 0;

	if (!QueueEmpty(&ms->q1)){

		//��q1��n-1��Ԫ�ذ��Ƶ�q2
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

//��ȡջ��Ԫ�أ�˫���У�
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

//�ö���ģ��ʵ��ջ
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