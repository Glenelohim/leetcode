/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
        	return head;
        int value = head->val;
        ListNode* p = head;
        ListNode* q = head->next;
        while (q)
        {
        	if (q->val == value)
        	{
        		p->next = q->next;
        		q = p->next;
        	}
        	else
        	{
        		value = q->val;
        		p = q;
        		q = q->next;
        	}
        }
        return head;
    }
};