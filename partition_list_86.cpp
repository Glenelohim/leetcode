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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next)
        	return head;
        ListNode* ltx = new ListNode(0);
        ListNode* gtx = new ListNode(0);
        ListNode* ll = ltx;
        ListNode* gg = gtx;

        while (head)
        {
        	if (head->val < x)
        	{
        		ll->next = head;
        		ll = ll->next;
        	}
        	else
        	{
        		gg->next = head;
        		gg = gg->next;
        	}
        	head = head->next;
        }
        gg->next = NULL;
        ll->next = gtx->next;
        return ltx->next;
    }
};