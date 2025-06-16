#include "Tree.hpp"

class Solution
{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        auto res = new TreeNode(val);
        if (!root) return res;
        auto cur = root;
        while (cur)
        {
            if (cur->left && cur->right)
            {
                if (cur->val > val)
                    cur = cur->left;
                else
                    cur = cur->right;
            }
            else if (!cur->left && !cur->right)
            {
                if (cur->val > val)
                    cur->left = res;
                else
                    cur->right = res;
                break;
            }
            else if (cur->left)
            {
                if (cur->val > val)
                    cur = cur->left;
                else
                {
                    cur->right = res;
                    break;
                }
            }
            else
            {
                if (cur->val > val)
                {
                    cur->left = res;
                    break;
                }
                else
                    cur = cur->right;
            }
        }
        return root;
    }
};
