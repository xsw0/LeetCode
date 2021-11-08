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
    inline ListNode* kth(ListNode* head, int k)
    {
        return k > 0 && head ? kth(head->next, k - 1) : head;
    };

    inline ListNode* reverse(ListNode* head)
    {
        ListNode* tail = nullptr;
        while (head)
        {
            auto next = head->next;
            head->next = tail;
            tail = head;
            head = next;
        }
        return tail;
    };

public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode _preHead{ 0, head };
        ListNode* preHead = &_preHead;
        auto preFirst = preHead;

        auto tail = kth(preFirst, k);
        while (tail)
        {
            auto next = tail->next;
            tail->next = nullptr;
            auto first = preFirst->next;
            preFirst->next = reverse(first);
            first->next = next;
            preFirst = first;
            tail = kth(preFirst, k);
        }
        return preHead->next;
    }
};
