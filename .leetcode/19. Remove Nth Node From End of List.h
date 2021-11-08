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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode node;
        node.next = head;
        ListNode* preHead = &node;
        auto last = head;
        while (n != 1)
        {
            last = last->next;
            --n;
        }
        ListNode* preNth = &node;
        while (last->next)
        {
            last = last->next;
            preNth = preNth->next;
        }
        auto next = preNth->next->next;
        delete preNth->next;
        preNth->next = next;
        return preHead->next;
    }
};
