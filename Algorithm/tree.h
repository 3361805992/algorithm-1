#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

typedef int ElementType;

typedef struct TreeNode
{
	ElementType data;				// ��ֵ��
	struct TreeNode* pLeftChiled;	// ��ڵ�
	struct TreeNode* pRightChild;	// �ҽڵ�
}TreeNode��*pTreeNode;

// ��������
void create_tree(TreeNode** pRoot, int * arrData ,int iArrLength);	// �������ṹ
int  isEmpty_tree(TreeNode* pRoot);									// �жϵ�ǰ���ṹ�Ƿ�ǿ�

// ��������
void create_tree(TreeNode** pRoot, ElementType * arrData) {

}

#endif // !TREE_H
