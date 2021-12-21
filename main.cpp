#include "bits/stdc++.h"

#include "ListNode.h"
#include "TreeNode.h"
#include "Node.h"

using namespace std;

#include ".leetcode/139. Word Break.h"

int main()
{
    Solution solution;

    auto arg1 = vector<int>{{ 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 }};
//    auto arg2 = vector<int>{ 9, 3, 15, 20, 7 };

//    ListNode* l = ListNode::pListNode(arg1.begin(), arg1.end());
//    TreeNode* tree = new TreeNode{
//        1,
//        new TreeNode{
//            2, new TreeNode{ 3 }, new TreeNode{ 4 }},
//        new TreeNode{
//            5, nullptr, new TreeNode{ 6 }}
//    };
//    auto result =
    solution.longestConsecutive(
        arg1
    );

//    solution.buildTree(arg1, arg2);

//    cout << result << endl;
//    for (auto& v: result)
//    {
//        for (auto i: v) cout << i << " ";
//        cout << "\n";
//    }
    return 0;
}
