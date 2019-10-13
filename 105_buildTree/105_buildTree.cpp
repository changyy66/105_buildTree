// 105_buildTree.cpp : 定义控制台应用程序的入口点。
//
/*
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

3
/ \
9  20
/  \
15   7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include "stdafx.h"
#include <vector>

using namespace std;

/**
* Definition for a binary tree node.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, int start1, int end1, vector<int>& inorder, int start2, int end2) {
		if (start1>end1)return NULL;
		TreeNode* root = new TreeNode(preorder[start1]);
		int i = start2;
		while (inorder[i] != preorder[start1])i++;

		root->left = buildTree(preorder, start1 + 1, start1 + (i - start2), inorder, start2, i - 1);
		root->right = buildTree(preorder, start1 + (i - start2) + 1, end1, inorder, i + 1, end2);
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
};

int main()
{
    return 0;
}

