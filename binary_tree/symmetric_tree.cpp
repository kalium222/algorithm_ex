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
