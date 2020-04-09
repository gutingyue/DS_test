#include "stack.h"
#include <assert.h>

void StackPrint(Stack* ps){
	assert(ps);
	for (int i = 0; i < ps->size; i++){
		printf("%d ", ps->array[i]);
	}
}

int main(){
	Stack s;
	StackInit(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	StackPrint(&s);

	printf("\n");

	StackPop(&s);
	StackPrint(&s);

	system("pause");
	return 0;
}