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
	TreeNode* buildTree_help(vector<int>& inorder, int i_low, int i_high, vector<int>& postorder, int p_low, int p_high)
	{
		if (i_low > i_high)
		{
			return NULL;
		}
		if (p_low >= p_high)
		{
			TreeNode* node = new TreeNode(postorder[p_low]);
			return node;
		}
		int index = i_low;
		for (; index <= i_high; index++)
		{
			if (postorder[p_high] == inorder[index])
				break;
		}
		TreeNode* node = new TreeNode(postorder[p_high]);
		node->right = buildTree_help(inorder, index+1, i_high, postorder, p_high-(i_high-index), p_high-1);
		node->left = buildTree_help(inorder, i_low, index-1, postorder, p_low, p_high-(i_high-index)-1);
	}

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
    	int size = inorder.size();
    	if (!size)
    	{
    		return NULL;
    	}
    	return buildTree_help(inorder, 0, size-1, postorder, 0, size-1);
    }
};