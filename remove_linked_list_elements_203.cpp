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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
        	return NULL;
        ListNode* res = NULL;  //point the first node not equal val
        ListNode* phead = head;
	    while (phead)
	    {
	        if (phead->val != val)
	        {
	        	res = phead;
	        	break;
	        }
	        phead = phead->next;
	    }
	    if (!res)  //all element removed
	    	return NULL;
	    ListNode* p = res;
	    while (p->next)
	    {
	    	if (p->next->val == val)
	    		p->next = p->next->next;
	    	else
	    		p = p->next;
	    }
	    return res;
    }
};