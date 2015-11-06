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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next)
		 	return NULL;

		int listLen = 0;
		int i = 1;
		ListNode* p = head;

		while (p)
		{
			listLen ++;
			p = p->next;
		}
		if (n >= listLen)
		{
		    head = head->next;
		    return head;
		}
		p = head;
		while (i < (listLen - n))
		{
			p = p->next;
			i ++;
		}
		if (!p->next->next)
		    p->next = NULL;
		else
		    p->next = p->next->next;
		return head;
    }
};