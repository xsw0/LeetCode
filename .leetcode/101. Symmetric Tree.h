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
    bool isSymmetric(struct TreeNode* p, struct TreeNode* q)
    {
        return p == nullptr && q == nullptr ||
               p && q &&
               p->val == q->val &&
               isSymmetric(p->left, q->right) &&
               isSymmetric(p->right, q->left);
    }

public:
    bool isSymmetric(TreeNode* root)
    {
        return isSymmetric(root->left, root->right);
    }
};
