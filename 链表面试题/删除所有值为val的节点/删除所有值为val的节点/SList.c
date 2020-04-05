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

//ɾ��������ֵΪval�Ľڵ�
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

//������ת
SLNode* reverseList(SLNode* head){
	if (head == NULL){
		return NULL;
	}

	SLNode* cur = head;
	SLNode* tail = head;

	while (cur->next){
		cur = cur->next;
	}
	SLNode* front = cur;

	while (cur != head){
		while (tail->next != cur){
			tail = tail->next;
		}
		cur->next = tail;
		cur = tail;
		tail = head;
	}
	head->next = NULL;
	return front;
}

//����������м�ڵ�
SLNode* middleNode(SLNode* head){
	if (head == NULL){
		return NULL;
	}
	SLNode* low = head;
	SLNode* fast = head;

	while (fast != NULL&&fast->next != NULL){
		fast = fast->next->next;
		low = low->next;
	}
	return low;
}

//������������k���ڵ�
SLNode* FindKthToTail(SLNode* pListHead, unsigned int k) {
	if (pListHead == NULL){
		return NULL;
	}
	SLNode* fast = pListHead;
	SLNode* slow = pListHead;

	for (; k>0 && fast != NULL; k--){  //��fast��slow����k����
		fast = fast->next;
	}

	if (k > 0){
		return NULL;
	}

	while (fast){
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}


//���������Ƿ�Ϊ���Ĵ�
int chkPalindrome(SLNode* A) {
	// write code here
	if (A == NULL || A->next == NULL){
		return 1;
	}
	SLNode* slow = A;
	SLNode* fast = A;
	while (fast&&fast->next){
		fast = fast->next->next;
		slow = slow->next;
	} //slowָ���м�ڵ�

	SLNode* cur = slow->next;
	SLNode* prve = cur;
	SLNode* L = NULL;
	//��ת��벿�ֵ�����
	while (cur){
		prve = cur->next;
		cur->next = L;
		L = cur;
		cur = prve;
	}
	//����ת��ĺ��������ǰ�벿�ֱȽ�
	while (L){
		if (L->data == A->data){
			A = A->next;
			L = L->next;
		}
		else{
			return 0;
		}
	}
	return 1;
}

//�ж������������Ƿ��ཻ�����ཻ�������ཻ�ڵ�
SLNode *getIntersectionNode(SLNode *headA, SLNode *headB) {
	if (headA == NULL || headB == NULL){
		return NULL;
	}
	int sizeA = 1;
	int sizeB = 1;
	SLNode* A = headA;
	SLNode* B = headB;

	while (A->next){
		sizeA++;
		A = A->next;
	}
	while (B->next){
		sizeB++;
		B = B->next;
	}

	if (A != B){//���������������һ���ڵ��λ�ò�ͬ�����������ཻ
		return NULL;
	}

	A = headA;
	B = headB;
	int num = sizeA - sizeB;
	if (num >= 0){
		while (num--){
			A = A->next;
		}
	}
	else{
		while (num++){
			B = B->next;
		}
	}
	while (A != B){
		A = A->next;
		B = B->next;
	}
	return A;

}

//�������л������л��������뻷��
SLNode *detectCycle(SLNode *head) {
	SLNode* fast = head;
	SLNode* slow = head;

	while (fast&&fast->next){
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow){//��fast==slow(��ָ��׷������ָ��)˵���������
			SLNode* cur = head;//cur��head��ʼ
			while (cur != fast){//fast�������㿪ʼ
				cur = cur->next;
				fast = fast->next;
			}
			return cur;
		}
	}

	return NULL;
}

int main(){


	system("pause");
	return 0;
}