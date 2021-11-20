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
    pair<int, int> _maxPathSum(TreeNode* root)
    {
        if (!root->left && !root->right) { return { root->val, root->val }; }
        if (root->left && root->right)
        {
            auto l = _maxPathSum(root->left);
            auto r = _maxPathSum(root->right);
            auto maximum = root->val + max(0, max(l.second, r.second));
            return { max(max(maximum, root->val + l.second + r.second), max(l.first, r.first)), maximum };
        }
        else
        {
            auto child = root->left ? _maxPathSum(root->left) : _maxPathSum(root->right);
            auto maximum = root->val + max(0, child.second);
            return { max(child.first, maximum), maximum };
        }
    }
public:
    int maxPathSum(TreeNode* root)
    {
        return _maxPathSum(root).first;
    }
};
