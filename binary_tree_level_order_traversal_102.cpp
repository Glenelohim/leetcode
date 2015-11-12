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
	void recresiveLevelOrder(vector<vector<int>>& result, TreeNode* root, int level)
	{
		if (!root)
			return;
		if (result.size() < level + 1)
		{
			vector<int> temp;
			temp.push_back(root->val);
			result.push_back(temp);
		}
		else  //brother node, use the space directly
		{
			result[level].push_back(root->val);
		}
		recresiveLevelOrder(result, root->left, level + 1);
		recresiveLevelOrder(result, root->right, level + 1);
	}

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root)
        	return result;
        recresiveLevelOrder(result, root, 0);
        return result;
    }
};