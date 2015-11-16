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
	void binarytree2stack(TreeNode* root, vector<vector<int>>& res, int height)
	{
		if (!root)
			return;
		if (res.size() < height + 1)
		{
			vector<int> temp;
			temp.push_back(root->val);
			res.push_back(temp);
		}
		else // brother node
		{
			res[height].push_back(root->val);
		}
		binarytree2stack(root->left, res, height + 1);
		binarytree2stack(root->right, res, height + 1);
	}

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root)
        	return result;
        vector<vector<int>> res;
        binarytree2stack(root, res, 0);
        for (int i = res.size() - 1; i >= 0; i --)
        	result.push_back(res[i]);
        return result;
    }
};

//another awesome solution cost 4ms
int depth(TreeNode *root) {
    if (!root) return 0;
    return max(depth(root->left),depth(root->right))+1;
}

void levelOrder(vector<vector<int>> &ans, TreeNode *node, int level) {
    if (!node) return;
    ans[level].push_back(node->val);
    levelOrder(ans,node->left,level-1);
    levelOrder(ans,node->right,level-1);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    int d = depth(root);
    vector<vector<int>> ans(d,vector<int> {});
    levelOrder(ans,root,d-1);
    return ans;
} 