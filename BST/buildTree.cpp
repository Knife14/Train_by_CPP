/*
title：重建二叉树
writer：山客
date：2021.8.4
example：
给出：
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回：
    3
   / \
  9  20
    /  \
   15   7
thinking:
①递归：在递归的每一部分中，其实都只是找到了属于根节点的点，从而最终递归出一整棵树
②在中序遍历中定位到根节点，即可知左子树和右子树的节点数目（相对于根节点而言）
*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	map<int, int> index;
public:
	TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, 
		int preorder_left, int preorder_right, int inorder_left, int inorder_right){
		if (preorder_left > preorder_right)
			return nullptr;

		// 先序遍历中第一个节点是根节点
		int preorder_root = preorder_left;
		// 在中序遍历中定位根节点
		int inorder_root = index[preorder[preorder_root]];
		// 并且建立根节点
		TreeNode* root = new TreeNode(preorder[preorder_root]);

		// 通过中序遍历得到左子树节点数目
		int size_left = inorder_root - inorder_left;

		// 递归构造左子树，并连接到根节点
		root->left = myBuildTree(
			preorder, inorder, 
			preorder_left + 1, preorder_left + size_left,
			inorder_left, inorder_root - 1
			);
		// 递归构造右子树，并连接根节点
		root->right = myBuildTree(
			preorder, inorder,
			preorder_root + size_left + 1, preorder_right,
			inorder_root + 1, inorder_right
			);

		return root;
	}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	int n = preorder.size();

    	// 构造哈希映射，帮助我们快速定位根节点
    	for(int i = 0; i < n; ++i){
    		index[inorder[i]] = i;
    	}

    	return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};
