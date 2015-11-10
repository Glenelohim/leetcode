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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
        	return true;
        if (!p || !q)
        	return false;

        bool flag1 = false;
        bool flag2 = false;
        if (p->val == q->val)
        {
        	flag1 = isSameTree(p->left, q->left);
        	flag2 = isSameTree(p->right, q->right);
        	if (flag1 && flag2)
        		return true;
        	else
        		return false;
        }
        else
        	return false;
    }
};