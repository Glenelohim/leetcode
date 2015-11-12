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
	bool isEqual(TreeNode* p, TreeNode* q)
	{
		if (!p && !q)
			return true;
		if (!p || !q)
			return false;
		return (p->val == q->val) && isEqual(p->left, q->right) && isEqual(p->right, q->left);
	}

    bool isSymmetric(TreeNode* root) {
        if (!root)
        	return true;

        return isEqual(root->left, root->right);
    }
};