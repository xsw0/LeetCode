/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode* partition(ListNode* head, int x)
    {
        ListNode less;
        ListNode greater;
        ListNode* tail_less = &less;
        ListNode* tail_greater = &greater;
        while (head)
        {
            if (head->val < x)
            {
                tail_less->next = head;
                tail_less = head;
            }
            else
            {
                tail_greater->next = head;
                tail_greater = head;
            }
            head = head->next;
        }
        tail_less->next = greater.next;
        tail_greater->next = nullptr;
        return less.next;
    }
};
