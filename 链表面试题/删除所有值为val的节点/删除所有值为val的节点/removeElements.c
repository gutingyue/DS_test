#include <stdio.h>
#include <Windows.h>

typedef int DataType;
typedef struct SLNode{
	DataType data;
	struct SLNode* next;
}SLNode;

//����ڵ㣬���ٿռ�
SLNode* BuySLNode(DataType data){
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));//����һ��SLNode��С�Ŀռ�
	if (NULL == newNode){
		printf("fail to apply\n");//����ʧ��
		assert(newNode);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}


//��ӡ����
void PrintSList(SLNode* psl){
	SLNode* cur = psl;
	while (cur){
		printf("%d --> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLNode* removeElements(SLNode* head, DataType val) {
	if (head == NULL){
		return NULL;
	}

	SLNode* cur = head;

	while (cur){
		if (cur->data == val&&val == head){
			head = cur->next;
			free(cur);
			cur = head;
		}
		else if ((cur->next)->data == val){
			SLNode* prev = cur;
			cur->next = prev->next;
			free(prev);
			cur = cur->next;
		}
		else{
			cur = cur->next;
		}
	}
	return head;
}
int main(){


	system("pause");
	return 0;
}