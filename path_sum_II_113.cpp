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
	void pathSum_help(TreeNode* root, int sum, vector<vector<int>>& res, vector<int> res_temp)
	{
		if (!root)
			return;
		
		if (!root->left && !root->right)  //leaf node
		{
			if (sum == root->val)
			{
				res_temp.push_back(root->val);
				res.push_back(res_temp);
				return;
			}
			return;
		}
		res_temp.push_back(root->val);
		pathSum_help(root->left, sum - root->val, res, res_temp);
		pathSum_help(root->right, sum - root->val, res, res_temp);
	}

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> result_temp;
        if (!root)
        	return result;
        pathSum_help(root, sum, result, result_temp);
        return result;
    }
};