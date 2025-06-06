#include <queue>
#include "Tree.hpp"

class Solution
{
public:
    int findBottomLeftValue(TreeNode* root)
    {
        std::queue<TreeNode*> q{};
        TreeNode *temp;
        int s;
        int res;
        q.push(root);
        while (!q.empty())
        {
            s = q.size();
            res = q.front()->val;
            for (int i=0; i<s; i++)
            {
                temp = q.front();
                q.pop();
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
        return res;
    }
};
