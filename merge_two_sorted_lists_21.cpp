/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if (!l1 && !l2)
        	return NULL;
        if (!l1)
        	return l2;
        if (!l2)
        	return l1;

        ListNode* p = l1->next;
        ListNode* q = l2->next;
        ListNode* head = NULL;
        if (l1->val <= l2->val)
        {
        	head = l1;
        	while (p && (p->val <= l2->val))
        	{
        		l1 = p;
        		p = p->next;
        	}
        	l1->next = l2;
        	l2->next = mergeTwoLists(p, q);
        }
        else
        {
        	head = mergeTwoLists(l2, l1);
        }
        return head;
    }
};