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
	int abs(int a, int b)
	{
		int res = a - b;
		if (res < 0)
			res = -res;
		return res;
	}
	int treeHeight(TreeNode* root)
	{
		if (!root)
			return 0;
		return (max(treeHeight(root->left), treeHeight(root->right)) + 1);
	}
    bool isBalanced(TreeNode* root) {
		if (!root)
			return true;

		if (abs(treeHeight(root->left), treeHeight(root->right)) > 1)
			return false;
		if (!isBalanced(root->left) || !isBalanced(root->right))
			return false;

		return true;
    }
};

//the previous solution can be conclude below
int depth(TreeNode* root) {
    return root?max(depth(root->left),depth(root->right))+1:0;
}
bool isBalanced(TreeNode* root) {
    return root?abs(depth(root->left)-depth(root->right))<=1&&isBalanced(root->left)&&isBalanced(root->right):true;
}