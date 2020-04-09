#include "stack.h"
#include <assert.h>
#include <malloc.h>
#include<stdio.h>
#include<Windows.h>

//ջ����
void CheckCapacity(Stack* ps){
	if (ps->size >= ps->capacity){
		//�����¿ռ�
		Datatype* temp = (Datatype*)malloc(sizeof(Datatype)*(ps->capacity) * 2);
		if (temp){
			//����Ԫ��
			//memcpy(temp,ps->array,sizeof(Datatype)*(ps->capacity);
			for (int i = 0; i < ps->size;i++){
				temp[i] = ps->array[i];
			}

			//�ͷžɿռ�
			free(ps->array);

			ps->array = temp;
		}
	}
}

//��ʼ��ջ
void StackInit(Stack* ps){
	assert(ps);
	ps->array = (Datatype*)malloc(sizeof(Datatype)* 5);//��ʼ����Ϊ5
	ps->capacity = 5;
	ps->size = 0;
}

//��ջ
void StackPush(Stack* ps, Datatype data){
	assert(ps);

	CheckCapacity(ps);//���ݺ���

	ps->array[ps->size] = data;
	ps->size++;
}

//��ջ
void StackPop(Stack* ps){
	assert(ps);

	if (StackEmpty(ps))//���ջ�Ƿ�Ϊ��
		return;

	ps->size--;
}

//��ȡջ��Ԫ��
Datatype StackTop(Stack* ps){
	assert(ps);

	return ps->array[ps->size - 1];
}

//��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps){
	assert(ps);
	return ps->size;
}

//����ջ�Ƿ�Ϊ��,Ϊ�շ��ط���
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