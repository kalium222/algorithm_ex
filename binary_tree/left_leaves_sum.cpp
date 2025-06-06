#include "Tree.hpp"

class Solution
{
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        int res = 0;
        if (!root) return res;
        if (root->right) res += sumOfLeftLeaves(root->right);
        TreeNode *left = root->left;
        if (left)
        {
            if (!left->left && !left->right)
                res += left->val;
            else
                res += sumOfLeftLeaves(left);
        }
        return res;
    }
};
