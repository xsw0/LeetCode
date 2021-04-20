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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1) return head;

        ListNode node;
        node.next = head;
        auto pre = &node;
        while (true)
        {
            auto p = pre;
            for (int i = 0; i < k; ++i)
            {
                auto first = p->next;
                auto second = first->third;
                p->next = third;
            }
        }
        return node.next;
    }
};
