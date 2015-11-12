/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	void findMax(TreeNode* root, int& depth, int level)
	{
		if (!root)
			return;
		if (depth < level + 1)
			depth ++;
		findMax(root->left, depth, level + 1);
		findMax(root->right, depth, level + 1);
	}

    int maxDepth(TreeNode* root) {
        if (!root)
        	return 0;
        int res = 0;
        findMax(root, res, 0);
        return res;
    }
};

//another elegant solution 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left),maxDepth(root->right)) + 1;
    }
};