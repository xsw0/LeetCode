/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        auto p_a = headA;
        auto p_b = headB;
        while (p_a != p_b)
        {
            p_a = p_a ? p_a->next : headB;
            p_b = p_b ? p_b->next : headA;
        }
        return p_a;
    }
};
