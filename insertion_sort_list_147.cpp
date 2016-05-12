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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
        {
        	return head;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* p = head;
        ListNode* cur = dummy;
        ListNode* q = NULL;
        while (p)
        {
        	cur = dummy;
        	while (cur->next && cur->next->val < p->val)
        	{
        		cur = cur->next;
        	}
        	q = p->next;
        	p->next = cur->next;
        	cur->next = p;
        	p = q;
        }

        return dummy->next;
    }
};