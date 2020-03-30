#include "SeqList.h"

//˳���ĳ�ʼ��
void SeqListInit(SeqList* psl, int capicity)//Ϊpslָ��Ľṹ�忪�ٿռ䣬�Խṹ����������ֶγ�ʼ��
{
	assert(psl);//���ԣ���ֹpslΪ��ָ��

	psl->array = (SLDataType*)malloc(capicity*sizeof(SLDataType));
	psl->capicity = capicity;
	psl->size = 0;
	
}

//˳�������
void SeqListDestory(SeqList* psl)//����ṹ��ĵ�ַ
{
	assert(psl);

	free(psl->array);//�ͷ�����ռ�
	psl->array = NULL;
	psl->size = 0;
	psl->capicity = 0;
}

//˳����ӡ
void SeqListPrint(SeqList* psl){
	assert(psl);

	int i = 0;
	for (; i < psl->size; i++){
		printf("%d ", psl->array[i]);
	}
	printf("\n");
}

//�жϿռ��Ƿ�����������
void CheckCapacity(SeqList* psl){
	assert(psl);

	if (psl->size == psl->capicity){//�жϿռ��Ƿ�����
		psl->array = (SLDataType*)realloc(psl->array, (psl->capicity * 2)*sizeof(SLDataType));
		//realloc���ص�ָ������Ϊ�գ�Ҫ�ı�ָ������ array������ΪSLDataType

		psl->capicity *= 2;//��������Ϊ������
	}
}

//˳���β��
void SeqListPushBack(SeqList* psl, SLDataType x){
	assert(psl);
	CheckCapacity(psl);

	psl->array[psl->size] = x;//��x��������һ����ЧԪ��֮��
	psl->size++;//��ЧԪ��+1
}

//˳���βɾ
void SeqListPopBack(SeqList* psl)
{
	assert(psl);

	psl->size--;
}

//˳���ͷ��
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

//˳���ͷɾ
void SeqListPopFront(SeqList* psl)
{
	assert(psl);

	int end = 0;
	for (; end < psl->size; end++){
		psl->array[end] = psl->array[end + 1];
	}
	psl->size--;
}

//˳������
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);

	int i = 0;
	for (; i < psl->size; i++){
		if (psl->array[i] == x){
			printf("Find %d\n�±�Ϊ%d\n", x, i);
			return i;
		}
	}
	printf("δ�ҵ�%d\n", x);
	return -1;//û���ҵ�������-1
}