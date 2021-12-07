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

        ListNode node(0, head);
        ListNode* p0 = &node;

        while (p0->next)
        {
            auto p1 = p0->next;
            if (p1)
            {
                auto p2 = p1->next;
                if (p2 && p2->val == p1->val)
                {
                    do
                    {
                        p1->next = p2->next;
                        delete p2;
                        p2 = p1->next;
                    } while (p2 && p2->val == p1->val);
                    delete p1;
                    p0->next = p2;
                    p1 = p0;
                }
            }
            p0 = p1;
        }

        return node.next;
    }
};
