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
    TreeNode* buildTree(
        vector<int>::const_iterator preorder_first,
        vector<int>::const_iterator preorder_last,
        vector<int>::const_iterator inorder_first,
        vector<int>::const_iterator inorder_last)
    {
        if (preorder_first == preorder_last) { return nullptr; }
        auto mid = find(inorder_first, inorder_last, *preorder_first);
        auto left = buildTree(
            next(preorder_first),
            preorder_first + distance(inorder_first, next(mid)),
            inorder_first,
            mid
        );
        auto right = buildTree(
            preorder_first + distance(inorder_first, next(mid)),
            preorder_last,
            next(mid),
            inorder_last
        );
        return new TreeNode(*preorder_first, left, right);
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return buildTree(preorder.cbegin(), preorder.cend(), inorder.cbegin(), inorder.cend());
    }
};
