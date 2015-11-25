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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2)	return NULL;
        if (!l1) return l2;
        if (!l2) return l1;

        int l1_len = 0, l2_len = 0;
        ListNode* p = l1;
        ListNode* q = l2;
        while (p)
        {
        	l1_len++;
        	p = p->next;
        }
        while (q)
        {
        	l2_len++;
        	q = q->next;
        }
        if (l1_len < l2_len) return addTwoNumbers(l2, l1);

        ListNode* res = new ListNode((l1->val + l2->val)%10);
        ListNode* rhead = res;
        int flag = (l1->val + l2->val) / 10;
        l1 = l1->next;
        l2 = l2->next;
        while (l2)
        {
        	ListNode* temp = new ListNode((l1->val + l2->val + flag)%10);
        	rhead->next = temp;
        	rhead = rhead->next;
        	flag = (l1->val + l2->val + flag) / 10;
        	l1 = l1->next;
        	l2 = l2->next;
        }
        while (l1)
        {
        	ListNode* temp = new ListNode((l1->val + flag)%10);
        	rhead->next = temp;
        	rhead = rhead->next;
        	flag = (l1->val + flag) / 10;
        	l1 = l1->next;
        }
        if (flag)
        {
        	ListNode* temp = new ListNode(flag);
        	rhead->next = temp;
        }
        return res;

    }
};