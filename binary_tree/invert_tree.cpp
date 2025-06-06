#include <utility>
#include "Tree.hpp"

class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (!root) return root;
        invertTree(root->right);
        std::swap(root->left, root->right);
        invertTree(root->right);
        return root;
    }
};
