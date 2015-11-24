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
	void buildPath(TreeNode* root, vector<string>& res, string path)
	{
		if (!root) return;

		path += "->";
		path += to_string(root->val);
		if (!root->left && !root->right)  //leaf node
		{
			res.push_back(path);
			return;
		}
		buildPath(root->left, res, path);
		buildPath(root->right, res, path);
	}

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        
       	string rootnode = to_string(root->val);
       	if (!root->left && !root->right)
       	{
       		res.push_back(rootnode);
       		return res;
       	}
       	buildPath(root->left, res, rootnode);
       	buildPath(root->right, res, rootnode);
       	return res;
    }
};