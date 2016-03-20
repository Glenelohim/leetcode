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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
        {
        	return;
        }

        //split the list into two parts
        ListNode* fast = head->next, *slow = head;
        while (fast && fast->next)
        {
        	fast = fast->next->next;
        	slow = slow->next;
        }

        //reverse the second list
        ListNode* s_head = slow->next;
        slow->next = NULL;
        ListNode* p = s_head, *q = s_head->next;
        ListNode* r = NULL, *t = NULL;
        while (q)
        {
        	r = p;
        	p = q;
        	q = q->next;
        	p->next = r;
        }
        s_head->next = NULL;
        s_head = p;

        //merge the two lists
        p = head;
        q = s_head;
        while (q)
        {
        	r = p->next;
        	t = q->next;
        	p->next = q;
        	q->next = r;
        	p = r;
        	q = t;
        }
    }
};



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //my solution is TLE...xx
class Solution {
public:
	ListNode* reorderList_help(ListNode* head)
	{
		if (!head || !head->next || !head->next->next)
        {
        	return head;
        }
		ListNode* seconde_node = head->next;
		ListNode* last_two_node = NULL;
		ListNode* last_node = NULL;
		ListNode* temp = seconde_node;
		while (temp)
		{
			if (temp->next == NULL)
			{
				last_node = temp;
				break;
			}
			else if (temp->next->next == NULL)
			{
				last_two_node = temp;
			}
			temp = temp->next;
		}
		last_two_node->next = NULL;
		head->next = last_node;
		last_node->next = reorderList_help(seconde_node);
		return head;
	}

    void reorderList(ListNode* head) {
        head = reorderList_help(head);
    }
};