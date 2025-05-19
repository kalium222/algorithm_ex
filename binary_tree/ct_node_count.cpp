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
    int countNodes(TreeNode* root)
    {
        if (!root) return 0;
        int dep = depth(root);
        if (dep>0) return (1<<dep) - 1;
        else
        {
            int l = 0, r = 0;
            if (root->left)
                l = countNodes(root->left);
            if (root->right)
                r = countNodes(root->right);
            return l + r + 1;
        }
    }

    int depth(TreeNode *root)
    {
        if (!root) return 0;
        auto l = root, r = root;
        int dep = 1;
        while (true)
        {
            if (l->left && r->right)
            {
                l = l->left;
                r = r->right;
                dep++;
            }
            else if (!l->left && !r->right)
            {
                return dep;
            }
            else
                return -1;
        }
    }
};
