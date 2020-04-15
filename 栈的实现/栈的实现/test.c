#include "stack.h"
#include <stdio.h>
#include <assert.h>

void StackPrint(Stack* ps){
	assert(ps);
	for (int i = 0; i < ps->size; i++){
		printf("%d ", ps->array[i]);
	}
}

//������������Ƿ�ƥ��
int Charpair(char s1,char s2){

	if (s1 == '('&&s2 == ')'){
		return 1;
	}
	else if (s1 == '['&&s2 == ']'){
		return 1;
	}
	else if (s1 == '{'&&s2 == '}'){
		return 1;
	}
	else{
		return 0;
	}

}

//������������Ƿ��Ӧ
int isValid(char * s){ 
	if (s==NULL){
		return 1;
	}
	Stack st;
	StackInit(&st);

	int size = strlen(s);
	for (int i = 0; i<size; i++){
		//���Ϊ�����ţ���ջ
		if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
			StackPush(&st, s[i]);

		}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}'){
			if (StackEmpty(&st))
				return 0;//ջ�п�

			if (Charpair(StackTop(&st), s[i])){ //�ж��Ƿ���ջ��Ԫ��ƥ��
				StackPop(&st); //��ջ
			}
			else{
				return 0;
			}
		}
	}

	if (StackSize(&st) == 0){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	//Stack s;
	//StackInit(&s);

	//StackPush(&s, 1);
	//StackPush(&s, 2);
	//StackPush(&s, 3);
	//StackPush(&s, 4);
	//StackPush(&s, 5);
	//StackPush(&s, 6);
	//StackPrint(&s);

	//printf("\n");

	//StackPop(&s);
	//StackPrint(&s);

	char* s = "(){}[]";
	int i=isValid(s);
	printf("%d \n", i);

	system("pause");
	return 0;
}