#include "Queue.h"

QNode* BuyNode(DataType data){
	QNode* newNode = (QNode*)malloc(sizeof(QNode));

	if (newNode == NULL){
		assert(0);
		return NULL;
	}

	newNode->val = data;
	newNode->next = NULL;
	return newNode;
}

//初始化队列
void QueueInit(Queue* q){
	assert(q);

	q->front = BuyNode(0);
	q->rear = q->front;
	q->size = 0;
}

//队列打印
void QueuePrint(Queue* q){
	assert(q);

	QNode* cur = q->front->next;
	if (cur){
		printf("%d ", cur->val);
		cur = cur->next;
	}
}

//入队 （队尾入）
void QueuePush(Queue* q, DataType data){
	assert(q);

	q->rear->next = BuyNode(data);
	q->rear = q->rear->next;
	q->size++;

}

//出队 （队头出）
void QueuePop(Queue* q){
	assert(q);

	if (q->front->next == NULL){ //若为空队列
		return;
	}

	QNode* tem = q->front->next;
	q->front->next = tem->next;
	free(tem);
	q->size--;
}

//获取队头元素
DataType QueueFront(Queue* q){
	assert(!QueueEmpty(q));

	return q->front->next->val;
}

//获取队尾元素
DataType QueueBack(Queue* q){
	assert(!QueueEmpty(q));

	return q->rear->val;
}

//获取队列有效元素个数
int QueueSize(Queue* q){
	assert(q);

	return q->size;
}

//检验队列是否为空，非空返回0
int QueueEmpty(Queue* q){
	assert(q);

	if (q->size){
		return 0;
	}
	return 1;

}

//销毁队列
void QueueDestroy(Queue* q){
	assert(q);

	if (q->front->next){
		QueuePop(q);
	}
}