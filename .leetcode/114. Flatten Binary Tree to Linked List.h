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
    void _flatten(TreeNode* root, TreeNode* right)
    {
        if (!root) { return; }
        auto p = root;
        if (right)
        {
            while (p->right) { p = p->right; }
            p->right = right;
        }
        if (root->left)
        {
            right = root->right;
            root->right = root->left;
            root->left = nullptr;
            _flatten(root->right, right);
        }
        else
        {
            _flatten(root->right, nullptr);
        }
    }
public:
    void flatten(TreeNode* root)
    {
        _flatten(root, nullptr);
    }
};
