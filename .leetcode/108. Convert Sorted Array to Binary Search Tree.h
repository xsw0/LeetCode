/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    static TreeNode* sortedArrayToBST(vector<int>::const_iterator first,
                                      vector<int>::const_iterator last)
    {
        if (first == last)
        {
            return nullptr;
        }
        auto mid = first + (last - first) / 2;
        return new TreeNode(
            *mid,
            sortedArrayToBST(first, mid),
            sortedArrayToBST(next(mid), last)
        );
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return sortedArrayToBST(nums.cbegin(), nums.cend());
    }
};
