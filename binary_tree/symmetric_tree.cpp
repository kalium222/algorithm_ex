#include "Tree.hpp"

class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        return symmetric(root->left, root->right);
    }

    bool symmetric(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return true;
        else if ((!left && right) || (left && !right))
            return false;
        else if (left->val!=right->val)
            return false;
        return symmetric(left->left, right->right) && symmetric(left->right, right->left);
    }
};
