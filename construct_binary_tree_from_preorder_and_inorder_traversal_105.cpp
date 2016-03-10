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
	TreeNode* buildTree_help(vector<int>& preorder, int p_low, int p_high, vector<int>& inorder, int i_low, int i_high)
	{
		if (i_low > i_high)
		{
			return NULL;
		}
		if (p_low >= p_high)
		{
			TreeNode* node = new TreeNode(preorder[p_low]);
			return node;
		}
		int index = i_low;
		for (; index <= i_high; index++)
		{
			if (preorder[p_low] == inorder[index])
				break;
		}
		TreeNode* node = new TreeNode(preorder[p_low]);
		node->left = buildTree_help(preorder, p_low + 1, p_low + (index - i_low), inorder, i_low, index - 1);
		node->right = buildTree_help(preorder, p_low + (index - i_low) + 1, p_high, inorder, index + 1, i_high);
	}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        if (!size)
        {
        	return NULL;
        }
        return buildTree_help(preorder, 0, size-1, inorder, 0, size-1);
    }
};