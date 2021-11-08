#include "bits/stdc++.h"

#include "ListNode.h"

using namespace std;

#include ".leetcode/81. Search in Rotated Sorted Array II.h"

int main()
{
    Solution solution;

    auto arg1 = vector<int>{ 1, 2, 3, 3, 4, 4, 5 };
    auto arg2 = 2;

    ListNode* ld = ListNode::pListNode(arg1.begin(), arg1.end());

    cout <<
         solution.deleteDuplicates(
             ld
         )
         << endl;
    return 0;
}
