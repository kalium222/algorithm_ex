#include <queue>
#include "Tree.hpp"

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        std::queue<TreeNode*> q{};
        int dep = 0;
        int s;
        if (!root) return dep;
        q.push(root);
        while (!q.empty())
        {
            s = q.size();
            for (int i=0; i<s; i++)
            {
                auto node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            dep++;
        }
        return dep;
    }
};
