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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
        	return head;
        ListNode* beforeCur = NULL;
        ListNode* cur = head;
        ListNode* afterCur = head->next;

        while (afterCur)
        {
        	cur->next = beforeCur;
        	beforeCur = cur;
        	cur = afterCur;
        	afterCur = cur->next;
        }
        cur->next = beforeCur;
        return cur;
    }
};