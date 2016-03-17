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
	int listLength(ListNode* head)
	{
		ListNode* p = head;
		int count = 0;
		while (p)
		{
			count++;
			p = p->next;
		}
		return count;
	}

    ListNode* rotateRight(ListNode* head, int k) {
        int len = listLength(head);
        if (!len)
        {
        	return NULL;
        }
        k %= len;
        if (0 == k)
        {
        	return head;
        }
        ListNode* q = head;
        ListNode* newhead = NULL, *last = NULL, *newend = NULL;
        int count = 0;
        while (q)
        {
        	count++;
        	if (count == (len - k))
        	{
        		newend = q;
        	}
        	if (count == (len - k + 1))
        	{
        		newhead = q;
        	}
        	if (count == len)
        	{
        		last = q;
        	}
        	q = q->next;
        }
        last->next = head;
        newend->next = NULL;
        return newhead;
    }
};