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
    void deleteNode(ListNode* node)
    {
        auto next = node->next;
        node->val = next->val;
        node->next = next->next;
        delete next;
    }
};

// this is a terrible problem
// in general, we do not change the value of node in a list problem.
