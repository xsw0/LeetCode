//
// Created by 0x0 on 11/19/21.
//

#ifndef LEETCODE_TREENODE_H
#define LEETCODE_TREENODE_H

#include <iostream>


class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x = 0, TreeNode* left = nullptr, TreeNode* right = nullptr)
        : val(x), left(left), right(right) {}
};


#endif //LEETCODE_TREENODE_H
