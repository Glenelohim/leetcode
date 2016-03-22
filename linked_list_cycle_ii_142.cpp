//here is the explanation
//https://leetcode.com/discuss/77721/implementation-much-clear-strict-explanation-give-more-clear
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
	//awesome solution from discuss
    ListNode *detectCycle(ListNode *head) {
        if (!head)
        	return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        bool flag = false;
        while (fast->next && fast->next->next)
        {
        	fast = fast->next->next;
        	slow = slow->next;
        	if (slow == fast)
        	{
        		flag = true;
        		break;
        	}
        }
        if (!flag)
        {
        	return NULL;
        }
        fast = head;
        while (fast != slow)
        {
        	fast = fast->next;
        	slow = slow->next;
        }
        return slow;
    }
};