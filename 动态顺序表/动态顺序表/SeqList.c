#include "SeqList.h"

//顺序表的初始化
void SeqListInit(SeqList* psl, int capicity)//为psl指向的结构体开辟空间，对结构体变量各个字段初始化
{
	assert(psl);//断言，防止psl为空指针

	psl->array = (SLDataType*)malloc(capicity*sizeof(SLDataType));
	psl->capicity = capicity;
	psl->size = 0;
	
}

//顺序表销毁
void SeqListDestory(SeqList* psl)//给入结构体的地址
{
	assert(psl);

	free(psl->array);//释放数组空间
	psl->array = NULL;
	psl->size = 0;
	psl->capicity = 0;
}

//顺序表打印
void SeqListPrint(SeqList* psl){
	assert(psl);

	int i = 0;
	for (; i < psl->size; i++){
		printf("%d ", psl->array[i]);
	}
	printf("\n");
}

//判断空间是否已满，增容
void CheckCapacity(SeqList* psl){
	assert(psl);

	if (psl->size == psl->capicity){//判断空间是否已满
		psl->array = (SLDataType*)realloc(psl->array, (psl->capicity * 2)*sizeof(SLDataType));
		//realloc返回的指针类新为空，要改变指针类型 array的类性为SLDataType

		psl->capicity *= 2;//容量更新为新容量
	}
}

//顺序表尾插
void SeqListPushBack(SeqList* psl, SLDataType x){
	assert(psl);
	CheckCapacity(psl);

	psl->array[psl->size] = x;//将x添加在最后一个有效元素之后
	psl->size++;//有效元素+1
}

//顺序表尾删
void SeqListPopBack(SeqList* psl)
{
	assert(psl);

	psl->size--;
}

//顺序表头插
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	int end = psl->size;
	while (end){
		psl->array[end] = psl->array[end-1];
		end--;
	}
	psl->array[0] = x;
	psl->size++;
}

//顺序表头删
void SeqListPopFront(SeqList* psl)
{
	assert(psl);

	int end = 0;
	for (; end < psl->size; end++){
		psl->array[end] = psl->array[end + 1];
	}
	psl->size--;
}

//顺序表查找
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);

	int i = 0;
	for (; i < psl->size; i++){
		if (psl->array[i] == x){
			printf("Find %d\n下标为%d\n", x, i);
			return i;
		}
	}
	printf("未找到%d\n", x);
	return -1;//没有找到，返回-1
}