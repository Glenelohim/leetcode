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
	void inorderTraversal_help(TreeNode* root, vector<int>& res)
	{
		if (!root)
		{
			return;
		}
		inorderTraversal_help(root->left, res);
		res.push_back(root->val);
		inorderTraversal_help(root->right, res);
	}

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
        {
        	return res;
        }
        inorderTraversal_help(root, res);
        return res;
    }
};