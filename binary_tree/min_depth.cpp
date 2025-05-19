#include <queue>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
                if (!node->right && !node->left) return dep+1;
            }
            dep++;
        }
        return dep;
    }
};
