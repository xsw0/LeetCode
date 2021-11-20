//
// Created by 0x0 on 5/18/21.
//

#ifndef LEETCODE__LISTNODE_H_
#define LEETCODE__LISTNODE_H_


class ListNode
{
public:
    int val;
    ListNode* next;
    explicit ListNode(int x = 0, ListNode* next = nullptr) : val(x), next(next) {}

    template<typename It>
    static ListNode* pListNode(It first, It last)
    {
        if (first == last)
        {
            return nullptr;
        }
        else
        {
            return new ListNode(*first, pListNode(std::next(first), last));
        }
    }
};

inline std::ostream& operator<<(std::ostream& os, ListNode* ld)
{
    assert(ld);
    os << ld->val;
    if (ld->next) os << ' ' << ld->next;
    return os;
}


#endif //LEETCODE__LISTNODE_H_
