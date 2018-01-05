#ifndef GETLASTCOMMONANCESTOR_H_
#define GETLASTCOMMONANCESTOR_H_

/*
 * ��������������͹�������
 */
#include <stdio.h>
#include <list>
#include <vector>

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode(int value) : m_nValue(value), m_pLeft(0), m_pRight(0) {}
};

/**
 * ��һ�����������������
 * �ⷨ����������������������
 */
BinaryTreeNode* GetLastCommonAncestorBST(BinaryTreeNode* pRoot, BinaryTreeNode* pNode1, BinaryTreeNode* pNode2) {
	if (pRoot == 0 || pNode1 == 0 || pNode2 == 0) {
		return 0;
	}
	//��ǰ���ֵ�����������ֵ��������
	if (pRoot->m_nValue > pNode1->m_nValue && pRoot->m_nValue > pNode2->m_nValue) {
		return GetLastCommonAncestorBST(pRoot->m_pLeft, pNode1, pNode2);
	}
	//��ǰ���ֵС���������ֵ��������
	else if (pRoot->m_nValue < pNode1->m_nValue && pRoot->m_nValue < pNode2->m_nValue) {
		return GetLastCommonAncestorBST(pRoot->m_pRight, pNode1, pNode2);
	}
	//��ǰ���ֵ��������һ����С����һ�����ߵ�������һ������ֵ������
	else {
		return pRoot;
	}
	return 0;
}


struct BinaryTreeNodeWithParent {
	int m_nValue;
	BinaryTreeNodeWithParent* m_pLeft;
	BinaryTreeNodeWithParent* m_pRight;
	BinaryTreeNodeWithParent* m_pParent;
	BinaryTreeNodeWithParent(int value) : m_nValue(value), m_pLeft(0), m_pRight(0), m_pParent(0) {}
};

/**
 * �ڶ��������һ��Ķ���������ָ�򸸽���ָ��
 * �ⷨ��ת��Ϊ����������ĵ�һ�������������
 */
BinaryTreeNodeWithParent* GetLastCommonAncestorBTP(BinaryTreeNodeWithParent* pRoot, BinaryTreeNodeWithParent* pNode1, BinaryTreeNodeWithParent* pNode2) {
	if (pRoot == 0 || pNode1 == 0 || pNode2 == 0) {
		return 0;
	}
	BinaryTreeNodeWithParent* pHead1 = pNode1;
	BinaryTreeNodeWithParent* pHead2 = pNode2;
	int length1 = 0;
	int length2 = 0;
	while (pHead1 != 0) {
		++length1;
		pHead1 = pHead1->m_pParent;
	}
	while (pHead2 != 0) {
		++length2;
		pHead2 = pHead2->m_pParent;
	}
	pHead1 = pNode1;
	pHead2 = pNode2;
	int diff = length1 - length2;
	if (diff > 0) {
		while (diff > 0) {
			pHead1 = pHead1->m_pParent;
			--diff;
		}
	}
	else if (diff < 0) {
		while (diff < 0) {
			pHead2 = pHead2->m_pParent;
			++diff;
		}
	}
	while (pHead1 != 0 && pHead2 != 0) {
		if (pHead1 == pHead2) {
			return pHead1;
		}
		pHead1 = pHead1->m_pParent;
		pHead2 = pHead2->m_pParent;
	}
	return 0;
}


/*
 * �����������һ��Ķ�����
 * �������Զ�������ȱ�������������ÿ��һ����㣬�����ýڵ��Ƿ����������㡣
 * ������ڵ����A��B����������������������A��B����˽ڵ�ΪLCA��������ڵ����A��B������ĳ������Ҳ����A��B������ȱ�����������
 */
bool IsInclude(BinaryTreeNode* pRoot, BinaryTreeNode* pNode1, BinaryTreeNode* pNode2, bool& bLeftInclude, bool& bRightInclude) {
	if (pRoot == 0) {
		return false;
	}
	if (pRoot == pNode1) {
		bLeftInclude = true;
	}
	if (pRoot == pNode2) {
		bRightInclude = true;
	}
	if (bLeftInclude && bRightInclude) {
		return true;
	}
	else {
		return IsInclude(pRoot->m_pLeft, pNode1, pNode2, bLeftInclude, bRightInclude) ||
		       IsInclude(pRoot->m_pRight, pNode1, pNode2, bLeftInclude, bRightInclude);
	}
}

bool IsInclude(BinaryTreeNode* pRoot, BinaryTreeNode* pNode1, BinaryTreeNode* pNode2) {
	if (pRoot == 0) {
		return false;
	}
	bool bLeftInclude = false;
	bool bRightInclude = false;
	return IsInclude(pRoot, pNode1, pNode2, bLeftInclude, bRightInclude);
}

BinaryTreeNode* GetLastCommonAncestorBT1(BinaryTreeNode* pRoot, BinaryTreeNode* pNode1, BinaryTreeNode* pNode2) {
	if (pRoot == 0 || pNode1 == 0 || pNode2 == 0) {
		return 0;
	}

	BinaryTreeNode* pLeft = 0;
	BinaryTreeNode* pRight = 0;

	bool bIsInclude = IsInclude(pRoot, pNode1, pNode2);
	if (!bIsInclude) {
		return 0;
	}
	else {
		pLeft = GetLastCommonAncestorBT1(pRoot->m_pLeft, pNode1, pNode2);
		pRight = GetLastCommonAncestorBT1(pRoot->m_pRight, pNode1, pNode2);
		if (pLeft == 0 && pRight == 0) {
			return pRoot;
		}
		else if (pLeft == 0) {
			return pRight;
		}
		else {
			return pLeft;
		}
	}
}


/*
 * �����������һ��Ķ�����
 * ��������ȱ�����ͬʱ��¼·��
 */
bool GetNodePathBT(BinaryTreeNode* pRoot, BinaryTreeNode* pNode, std::list<BinaryTreeNode*>& path) {
	//���ҵĽ����Ŀ��ڵ㣬Ŀ��ڵ㲻�÷���path
	if (pRoot == pNode) {
		return true;
	}
	path.push_back(pRoot);
	bool found = false;
	if (GetNodePathBT(pRoot->m_pLeft, pNode, path) || GetNodePathBT(pRoot->m_pRight, pNode, path)) {
		found = true;
	}
	if (!found) {
		path.pop_back();
	}
	return found;
}

BinaryTreeNode* GetLastCommonNodeBT(std::list<BinaryTreeNode*>& path1, std::list<BinaryTreeNode*>& path2) {
	std::list<BinaryTreeNode*>::iterator it1 = path1.begin();
	std::list<BinaryTreeNode*>::iterator it2 = path2.begin();
	TreeNode* pLast = 0;
	while (it1 != path1.end() && it2 != path2.end()) {
		if (*it1 == *it2) {
			pLast = *it1;
		}
		else {
			break;
		}
		++it1;
		++it2;
	}
	return pLast;
}

BinaryTreeNode* GetLastCommonAncestorBT2(BinaryTreeNode* pRoot, BinaryTreeNode* pNode1, BinaryTreeNode* pNode2) {
	if (pRoot == 0 || pNode1 == 0 || pNode2 == 0) {
		return 0;
	}
	std::list<BinaryTreeNode*> path1;
	GetNodePathBT(pRoot, pNode1, path1);
	std::list<BinaryTreeNode*> path2;
	GetNodePathBT(pRoot, pNode2, path2);

	return GetLastCommonNodeBT(path1, path2);
}


/*
 * �����������һ�����
 * ��������ȱ�����ͬʱ��¼·��
 */
struct TreeNode {
	int m_nValue;
	std::vector<TreeNode*> m_vChildren;
};

bool GetNodePath(TreeNode* pRoot, TreeNode* pNode, std::list<TreeNode*>& path) {
	path.push_back(pRoot);
	bool found = false;
	std::vector<TreeNode*>::iterator it = pRoot->m_vChildren.begin();
	while (!found && it != pRoot->m_vChildren.end()) {
		found = GetNodePath(*it, pNode, path);
		++it;
	}
	if (!found) {
		path.pop_back();
	}
	return found;
}

TreeNode* GetLastCommonNode(std::list<TreeNode*>& path1, std::list<TreeNode*>& path2) {
	std::list<TreeNode*>::iterator it1 = path1.begin();
	std::list<TreeNode*>::iterator it2 = path2.begin();
	TreeNode* pLast = 0;
	while (it1 != path1.end() && it2 != path2.end()) {
		if (*it1 == *it2) {
			pLast = *it1;
		}
		else {
			break;
		}
		++it1;
		++it2;
	}
	return pLast;
}

TreeNode* GetLastCommonAncestor(TreeNode* pRoot, TreeNode* pNode1, TreeNode* pNode2) {
	if (pRoot == 0 || pNode1 == 0 || pNode2 == 0) {
		return 0;
	}
	std::list<TreeNode*> path1;
	GetNodePath(pRoot, pNode1, path1);
	std::list<TreeNode*> path2;
	GetNodePath(pRoot, pNode2, path2);

	return GetLastCommonNode(path1, path2);
}


#endif /* GETLASTCOMMONANCESTOR_H_ */
