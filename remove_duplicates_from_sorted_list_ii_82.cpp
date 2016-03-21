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
        if (!head->next->next && (head->val != head->next->val))
        	return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = pre->next;
        ListNode* after = cur->next;
        int count = 0;
        while (after)
        {
        	count = 0;
        	while (after && after->val == cur->val)
        	{
        		after = after->next;
        		count++;
        	}
        	if (0 == count)
        	{
        		pre->next = cur;
        		pre = cur;
        		cur = pre->next;
        		after = cur->next;
        	}
        	else if (!after || !after->next)
        	{	
        		pre->next = after;
        		break;
        	}
        	else if (after->val != after->next->val)
        	{
        		pre->next = after;
        		pre = after;
        		cur = pre->next;
        		after = cur->next;
        	}
        	else if (after->val == after->next->val)
        	{
        		cur = after;
        		after = after->next;
        	}
        }
        return dummy->next;
    }
};