#include <stdio.h>
#include <Windows.h>

typedef int DataType;
typedef struct SLNode{
	DataType data;
	struct SLNode* next;
}SLNode;

//申请节点，开辟空间
SLNode* BuySLNode(DataType data){
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));//申请一个SLNode大小的空间
	if (NULL == newNode){
		printf("fail to apply\n");//申请失败
		assert(newNode);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}


//打印链表
void PrintSList(SLNode* psl){
	SLNode* cur = psl;
	while (cur){
		printf("%d --> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//删除链表中值为val的节点
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

//单链表翻转
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

//返回链表的中间节点
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

//返回链表倒数第k个节点
SLNode* FindKthToTail(SLNode* pListHead, unsigned int k) {
	if (pListHead == NULL){
		return NULL;
	}
	SLNode* fast = pListHead;
	SLNode* slow = pListHead;

	for (; k>0 && fast != NULL; k--){  //让fast比slow多走k布步
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


//检验链表是否为回文串
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
	} //slow指向中间节点

	SLNode* cur = slow->next;
	SLNode* prve = cur;
	SLNode* L = NULL;
	//翻转后半部分的链表
	while (cur){
		prve = cur->next;
		cur->next = L;
		L = cur;
		cur = prve;
	}
	//将翻转后的后半链表与前半部分比较
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

//判断两个单链表是否相交，若相交，返回相交节点
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

	if (A != B){//如果两个链表的最后一个节点的位置不同，则两链表不相交
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

//单链表判环，若有环，返回入环点
SLNode *detectCycle(SLNode *head) {
	SLNode* fast = head;
	SLNode* slow = head;

	while (fast&&fast->next){
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow){//若fast==slow(快指针追上了慢指针)说明链表带环
			SLNode* cur = head;//cur从head开始
			while (cur != fast){//fast从相遇点开始
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