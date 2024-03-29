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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (!head) return nullptr;
        auto p = head;
        while (p->next)
        {
            auto next = p->next;
            if (next->val == p->val)
            {
                p->next = next->next;
                delete next;
            }
            else { p = p->next; }
        }
        return head;
    }
};
