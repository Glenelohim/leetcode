/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //stupid solution
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if (NULL == l1)
		{
			return l2;
		}
		if (NULL == l2)
		{
			return l1;
		}

		if (l1->val <= l2->val)
		{
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else
		{
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int list_size = lists.size();
        if (0 == list_size)
        {
        	return NULL;
        }
        ListNode* head = lists[0];
        for (int i=1; i<list_size; i++)
        {
        	head = mergeTwoLists(head, lists[i]);
        }

        return head;
    }
};