#include "bits/stdc++.h"
#include "ListNode.h"

using namespace std;

#include ".leetcode/25. Reverse Nodes in k-Group.h"

int main()
{
    list<int> a;
    vector<int> v{ 1, 2, 3, 4, 5 };
    ListNode *ln = ListNode::pListNode(v.cbegin(), v.cend());
    Solution solution;
    ln = solution.reverseKGroup(ln, 2);
    std::cout << ln << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
