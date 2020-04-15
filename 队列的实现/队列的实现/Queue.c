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

//��ʼ������
void QueueInit(Queue* q){
	assert(q);

	q->front = BuyNode(0);
	q->rear = q->front;
	q->size = 0;
}

//���д�ӡ
void QueuePrint(Queue* q){
	assert(q);

	QNode* cur = q->front->next;
	if (cur){
		printf("%d ", cur->val);
		cur = cur->next;
	}
}

//��� ����β�룩
void QueuePush(Queue* q, DataType data){
	assert(q);

	q->rear->next = BuyNode(data);
	q->rear = q->rear->next;
	q->size++;

}

//���� ����ͷ����
void QueuePop(Queue* q){
	assert(q);

	if (q->front->next == NULL){ //��Ϊ�ն���
		return;
	}

	QNode* tem = q->front->next;
	q->front->next = tem->next;
	free(tem);
	q->size--;
}

//��ȡ��ͷԪ��
DataType QueueFront(Queue* q){
	assert(!QueueEmpty(q));

	return q->front->next->val;
}

//��ȡ��βԪ��
DataType QueueBack(Queue* q){
	assert(!QueueEmpty(q));

	return q->rear->val;
}

//��ȡ������ЧԪ�ظ���
int QueueSize(Queue* q){
	assert(q);

	return q->size;
}

//��������Ƿ�Ϊ�գ��ǿշ���0
int QueueEmpty(Queue* q){
	assert(q);

	if (q->size){
		return 0;
	}
	return 1;

}

//���ٶ���
void QueueDestroy(Queue* q){
	assert(q);

	if (q->front->next){
		QueuePop(q);
	}
}