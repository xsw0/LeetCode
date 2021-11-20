//
// Created by 0x0 on 11/20/21.
//

#ifndef LEETCODE_NODE_H
#define LEETCODE_NODE_H


class Node
{
public:
    int val;
    Node* next;
    Node* random;

    explicit Node(int val) : val{ val }, next{ nullptr }, random{ nullptr } {}
};


#endif //LEETCODE_NODE_H
