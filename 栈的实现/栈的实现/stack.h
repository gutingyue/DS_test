#pragma once

typedef int Datatype;

typedef struct Stack{
	Datatype* array; //����ռ�
	int size;     //��Ч����
	int capacity;//����
}Stack;

//��ʼ��ջ
void StackInit(Stack* ps);

//��ջ
void StackPush(Stack* ps, Datatype data);
//��ջ
void StackPop(Stack* ps);

//��ȡջ��Ԫ��
Datatype StackTop(Stack* ps);

//��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps);

//����ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps);
