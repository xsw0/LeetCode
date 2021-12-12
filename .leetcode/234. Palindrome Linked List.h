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
    static ListNode* reverse(ListNode* head)
    {
        if (!head) { return head; }
        ListNode* pre = nullptr;
        while (head)
        {
            auto next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

    static ListNode* mid(ListNode* head)
    {
        if (!head) { return nullptr; }
        auto fast = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            head = head->next;
        }
        return head;
    }
public:
    bool isPalindrome(ListNode* head)
    {
        auto last_half = mid(head)->next;
        last_half = reverse(last_half);
        auto left = head;
        auto right = last_half;
        while (right)
        {
            if (left->val != right->val)
            {
//                last_half = reverse(last_half);
                return false;
            }
            left = left->next;
            right = right->next;
        }
//        last_half = reverse(last_half);
        return true;
    }
};
