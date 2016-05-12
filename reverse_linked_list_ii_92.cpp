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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n || !head || !head->next)
        {
        	return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        int i = 1;
        for (; i < m; i++)
        {
        	p = p->next;
        }
        ListNode* phead = p->next;
        ListNode* cur = phead;
        ListNode* after = cur->next, *pre = cur;
        for (i = m; i < n; i++)
        {
        	pre = cur;
        	cur = after;
        	after = after->next;
        	cur->next = pre;
        }
        p->next = cur;
        phead->next = after;

        return dummy->next;
    }
};