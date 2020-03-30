#pragma one
#include<stdio.h>
#include<Windows.h>

typedef int BTDataType;

typedef struct BinTreeNode{
	BTNode* pLeft;//ָ������
	BTNode* pRight;//ָ���Һ���
	BTDataType val;

}BTNode;

//ͨ��ǰ��������������鹹��������
BTNode* BTCreate(BTDataType* arr, int n, int pi);
//���ٶ�����
void BTDestory(BTNode** proot);

//ǰ�����
void PreOrder(BTNode* proot);
//�������
void InOrder(BTNode* proot);
//�������
void PostOrder(BTNode* proot);

//��ȡ�������ڵ�ĸ���
int GetNodeSize(BTNode* proot);
//��ȡ������Ҷ�ӽڵ�ĸ���
int GetLeafCount(BTNode* proot);
//��ȡ��K��ڵ�ĸ���
int GetKleveNodeCount(BTNode* proot);
//��ȡ�������ĸ߶�
int GetHight(BTNode* proot);

//�ڶ��������ҳ�xԪ�ض�Ӧ�Ľڵ�
BTNode* Find(BTNode* proot, BTDataType x);
//��ȡpNode��˫��
BTNode* GetParent(BTNode* proot, BTNode* pNode);