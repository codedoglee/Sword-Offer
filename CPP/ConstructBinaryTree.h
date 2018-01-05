#ifndef CONSTRUCTBINARYTREE_H_
#define CONSTRUCTBINARYTREE_H_

/**
 * ��Ŀ������ĳ��������ǰ���������������Ľ�������ؽ����ö�������
 * ���������ǰ���������������Ľ���ж��������ظ������֡�
 * ��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}��
 */
#include <cstdio>
#include <queue>
#include <exception>
#include <stdexcept>

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode(int value) : m_nValue(value), m_pLeft(0), m_pRight(0) {}
};

BinaryTreeNode* ConstructTree(int* preStart, int* preEnd, int* inStart, int* inEnd) {
	int rootValue = preStart[0];
	BinaryTreeNode *root = new BinaryTreeNode(rootValue);		// ǰ�������һ��Ԫ���Ǹ��ڵ�
	if (preStart == preEnd) {
		if (inStart == inEnd && *preStart == *inStart) {
			return root;
		}
		else {
			std::runtime_error err("Invalid input!\n");
			throw err;
		}
	}
	int* rootInorder = inStart;
	while (rootInorder <= inEnd && *rootInorder != rootValue) {
		++rootInorder;
	}
	if (rootInorder == inEnd + 1) {
		std::runtime_error err("Invalid input!\n");
		throw err;
	}

	int leftLength = rootInorder - inStart;
	int* leftPreEnd = preStart + leftLength;
	if (leftLength > 0) {
		root->m_pLeft = ConstructTree(preStart + 1, leftPreEnd, inStart, rootInorder - 1);
	}
	if (leftLength < preEnd - preStart) {
		root->m_pRight = ConstructTree(leftPreEnd + 1, preEnd, rootInorder + 1, inEnd);
	}
	return root;
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
	if (preorder == 0 || inorder == 0 || length <= 0) {
		return 0;
	}
	return ConstructTree(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

void ConstructTreeTest() {
	int pre[] = {1,2,4,7,3,5,6,8};
	int in[] = {4,7,2,1,5,3,8,6};
	BinaryTreeNode* root = Construct(pre, in, 8);
	if (root == 0) {
		printf("error!");
	}
	std::queue<BinaryTreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		if (q.front()) {
			printf("%d\t", q.front()->m_nValue);
			if (q.front()->m_pLeft) {
				q.push(q.front()->m_pLeft);
			}
			if (q.front()->m_pRight) {
				q.push(q.front()->m_pRight);
			}
			q.pop();
		}
	}
}


#endif /* CONSTRUCTBINARYTREE_H_ */
