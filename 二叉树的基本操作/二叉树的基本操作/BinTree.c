#include "BinaryTree.h"

//ǰ�����
void PreOrder(BTNode* proot){
	//��root��ָ���
	if (proot){ 
		printf("%d/n", proot->val);
		preOrder(proot->pLeft);
		preOrder(proot->pRight);
	}
}

//�������
void InOrder(BTNode* proot){

	if (proot){
		preOrder(proot->pLeft);
		printf("%d/n", proot->val);
		preOrder(proot->pRight);
	}
}

//�������
void PostOrder(BTNode* proot){

	if (proot){
		preOrder(proot->pLeft);
		preOrder(proot->pRight);
		printf("%d/n", proot->val);
	}
}