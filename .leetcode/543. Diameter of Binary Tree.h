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
    pair<int, int> diameter(TreeNode* root)
    {
        if (!root) { return { 0, 0 }; }
        auto left = diameter(root->left);
        auto right = diameter(root->right);
        return { max(max(left.first, right.first), left.second + right.second + 1),
                 1 + max(left.second, right.second) };
    }
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        return diameter(root).first - 1;
    }
};
