/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
        {
        	return NULL;
        }
        if (!head->next)
        {
        	TreeNode* root = new TreeNode(head->val);
        	return root;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next)
        {
        	slow = slow->next;
        	fast = fast->next->next;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        while (dummy->next != slow)
        {
        	dummy = dummy->next;
        }
        fast = slow->next;
        dummy->next = NULL;
        TreeNode* root = new TreeNode(slow->val);
        if (slow == head)
        {
        	root->left = sortedListToBST(NULL);
        }
        else
        {
        	root->left = sortedListToBST(head);
        }
        root->right = sortedListToBST(fast);
        return root;
    }
};