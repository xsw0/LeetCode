#include "bits/stdc++.h"

#include "ListNode.h"

using namespace std;

#include ".leetcode/84. Largest Rectangle in Histogram.h"

int main()
{
    Solution solution;

    auto arg1 = vector<int>{ 4, 2, 0, 3, 2, 4, 3, 4 };
    auto arg2 = 2;

    ListNode* ld = ListNode::pListNode(arg1.begin(), arg1.end());

    cout <<
         solution.largestRectangleArea(
             arg1
         )
         << endl;
    return 0;
}
