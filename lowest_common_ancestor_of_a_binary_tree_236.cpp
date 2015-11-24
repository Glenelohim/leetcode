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
	//using recursive
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
        if(root == p || root == q)
            return root;
    
        if(left != NULL && right == NULL)
            return left;
        else if(left == NULL && right != NULL)
            return right;
        else if(left == NULL && right == NULL)
            return NULL;
        else
            return root;
    }
};