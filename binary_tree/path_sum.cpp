#include "Tree.hpp"

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return false;
        }
        else if (!root->left && !root->right)
        {
            return targetSum == root->val;
        }
        else
        {
            int rest = targetSum - root->val;
            return hasPathSum(root->left, rest)
                || hasPathSum(root->right, rest);
        }
    }
};
