#include "Tree.hpp"

class Solution
{
private:
    // NOTE: mediem
    TreeNode* recur(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root) return nullptr;
        else if (root==p || root ==q) return root;
        auto _left = recur(root->left, p, q);
        auto _right = recur(root->right, p, q);
        if (!_left && !_right) return nullptr;
        else if (_left && _right) return root;
        else return _left ? _left : _right;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        return recur(root, p, q);
    }
};
