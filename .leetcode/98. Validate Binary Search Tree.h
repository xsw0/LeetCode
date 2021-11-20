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
public:
    bool b = false;
    int64_t pre = numeric_limits<int64_t>::min();
    bool isValidBST(TreeNode* root)
    {
        if (!root) return true;
        if (!isValidBST(root->left)) { return false; }
        if (b && root->val <= pre) { return false; }
        b = true;
        pre = root->val;
        if (!isValidBST(root->right)) { return false; }
        return true;
    }
};
