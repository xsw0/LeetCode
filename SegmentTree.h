//
// Created by 0x0 on 11/19/21.
//

#ifndef LEETCODE_SEGMENTTREE_H
#define LEETCODE_SEGMENTTREE_H

#include <map>

template<class Key, class Tp, class Compare = less <_Key>>
class SegmentTree
{
    std::map<Key, Tp, Compare> m{};
    SegmentTree() {};

    void insert(_Key k) {}
    void erase() {}

};


#endif //LEETCODE_SEGMENTTREE_H
