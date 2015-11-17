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
	//fuck this problem, fuck its case
	//reference from the discuss
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
        	return NULL;
        int a_len = 0, b_len = 0;
        for (ListNode* a = headA; a != NULL; a = a->next, a_len++);
        for (ListNode* b = headB; b != NULL; b = b->next, b_len++);

        ListNode* shortlist = a_len < b_len ? headA : headB;
    	ListNode* longlist = a_len < b_len ? headB : headA;

    	for (int i = 0; i < std::abs(a_len - b_len); i++)
    		longlist = longlist->next;

    	while (longlist && longlist->val != shortlist->val)
    	{
    		longlist = longlist->next;
    		shortlist = shortlist->list;
    	}
    	return longlist;

    }
};