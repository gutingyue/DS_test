#pragma one
#include<stdio.h>
#include<Windows.h>

typedef int BTDataType;

typedef struct BinTreeNode{
	BTNode* pLeft;//指向左孩子
	BTNode* pRight;//指向右孩子
	BTDataType val;

}BTNode;

//通过前序遍历，依据数组构建二叉树
BTNode* BTCreate(BTDataType* arr, int n, int pi);
//销毁二叉树
void BTDestory(BTNode** proot);

//前序遍历
void PreOrder(BTNode* proot);
//中序遍历
void InOrder(BTNode* proot);
//后序遍历
void PostOrder(BTNode* proot);

//获取二叉树节点的个数
int GetNodeSize(BTNode* proot);
//获取二叉树叶子节点的个数
int GetLeafCount(BTNode* proot);
//获取第K层节点的个数
int GetKleveNodeCount(BTNode* proot);
//获取二叉树的高度
int GetHight(BTNode* proot);

//在二叉树中找出x元素对应的节点
BTNode* Find(BTNode* proot, BTDataType x);
//获取pNode的双亲
BTNode* GetParent(BTNode* proot, BTNode* pNode);