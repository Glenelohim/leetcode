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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
        	return head;
        ListNode* firstEven = head->next;
        ListNode* odd = head;
        ListNode* even = firstEven;
        while (odd && even && odd->next && even->next)
        {
        	odd->next = odd->next->next;
        	even->next = even->next->next;
        	odd = odd->next;
        	even = even->next;
        }
        odd->next = firstEven;
        return head;
    }
};