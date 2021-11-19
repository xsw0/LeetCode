#include "bits/stdc++.h"

#include "ListNode.h"
#include "TreeNode.h"

using namespace std;

#include ".leetcode/94. Binary Tree Inorder Traversal.h"

int main()
{
    Solution solution;

    auto arg1 = "111111111111111111111111111111111111111111111";
    auto arg2 = "sre";

//    ListNode* ld = ListNode::pListNode(arg1.begin(), arg1.end());

    auto result = solution.numDecodings(
        arg1
    );

    cout << result << endl;
//    for (auto& v: result)
//    {
//        for (auto i: v) cout << i << " ";
//        cout << "\n";
//    }
    return 0;
}
