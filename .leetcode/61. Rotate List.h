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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (!head) return nullptr;
        int length = 1;
        ListNode* tail = head;
        while (tail->next)
        {
            tail = tail->next;
            ++length;
        }
        k %= length;
        if (k == 0) return head;
        k = length - k - 1;
        auto p = head;
        while (k-- > 0)
        {
            p = p->next;
        }
        tail->next = head;
        head = p->next;
        p->next = nullptr;
        return head;
    }
};
