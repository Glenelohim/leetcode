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
	//o(n)time o(n)space
	ListNode* traverseList(ListNode* head)
	{
		if (!head)
			return NULL;
		if (!head->next)
			return head;
		ListNode* before = head;
		ListNode* current = head->next;
		ListNode* after = current->next;
		before->next = NULL;
		while (after)
		{
			current->next = before;
			before = current;
			current = after;
			after = after->next;
		}
		current->next = before;
		return current;
	}

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
        	return true;
        //point the mid of list using two pionter
        ListNode* fast = head;
        ListNode* mid = head;
        while (fast && fast->next)
        {
        	mid = mid->next;
        	fast = fast->next->next;
        }
        if (fast)  //means that the number of node is odd
        	mid = traverseList(mid->next);
        else  //number of node is even
        	mid = traverseList(mid);
        while (mid)
        {
        	if (head->val != mid->val)
        		return false;
        	head = head->next;
        	mid = mid->next;
        }
        return true;
    }
};

//awesome solution using recursive
class Solution {
public:
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }

    bool check(ListNode* p) {
        if (NULL == p) return true;
        bool isPal = check(p->next) & (temp->val == p->val);
        temp = temp->next;
        return isPal;
    }
};