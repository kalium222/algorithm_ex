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
