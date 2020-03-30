#include "BinaryTree.h"

//前序遍历
void PreOrder(BTNode* proot){
	//若root不指向空
	if (proot){ 
		printf("%d/n", proot->val);
		preOrder(proot->pLeft);
		preOrder(proot->pRight);
	}
}

//中序遍历
void InOrder(BTNode* proot){

	if (proot){
		preOrder(proot->pLeft);
		printf("%d/n", proot->val);
		preOrder(proot->pRight);
	}
}

//后序遍历
void PostOrder(BTNode* proot){

	if (proot){
		preOrder(proot->pLeft);
		preOrder(proot->pRight);
		printf("%d/n", proot->val);
	}
}