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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        vector<int> v;
        v.reserve(min(static_cast<size_t>(10000),
                      lists.size() * static_cast<size_t>(500)));
        for (auto list: lists)
        {
            while (list)
            {
                v.push_back(list->val);
                list = list->next;
            }
        }
        sort(v.begin(), v.end());
        ListNode node;
        ListNode* preHead = &node;
        for (const auto i: v)
        {
            preHead->next = new ListNode(i);
            preHead = preHead->next;
        }
        preHead->next = nullptr;
        return node.next;
    }
};
