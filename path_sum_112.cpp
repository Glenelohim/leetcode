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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
        	return false;
        
        if (!root->left && !root->right)  //leaf node
        {
        	if (sum == root->val)
        		return true;
        	else
        		return false;
        }
		if (hasPathSum_help(root->left, sum - root->val))
        	return true;
        if (hasPathSum_help(root->right, sum - root->val))
        	return true;

        return false;
    }
};