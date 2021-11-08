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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode node;
        node.next = head;
        auto preNth = &node;
        auto result = preNth;
        while (preNth->next && preNth->next->next)
        {
            auto first = preNth->next;
            auto second = first->next;
            auto third = second->next;
            preNth->next = second;
            second->next = first;
            first->next = third;
            preNth = first;
        }
        return node.next;
    }
};
