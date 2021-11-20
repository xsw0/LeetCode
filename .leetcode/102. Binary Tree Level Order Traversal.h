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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (!root) { return {}; }

        list<TreeNode*> cur{ root };
        list<TreeNode*> next;
        vector<vector<int>> result;
        while (!cur.empty())
        {
            result.emplace_back();
            for (const auto& e: cur)
            {
                result.back().push_back(e->val);
                if (e->left) { next.push_back(e->left); }
                if (e->right) { next.push_back(e->right); }
            }
            cur = std::move(next);
            next.clear();
        }
        return result;
    }
};
