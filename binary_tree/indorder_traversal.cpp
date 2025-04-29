#include <stack>
#include <vector>
using namespace std;

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
    vector<int> inorderTraversal(TreeNode* root)
    {
        return method1(root);
    }

    // recursively
    vector<int> method1(TreeNode* root)
    {
        vector<int> res{};
        traverse(root, res);
        return res;
    }

    void traverse(TreeNode *root, vector<int> &res)
    {
        if (!root) return;
        traverse(root->left, res);
        res.push_back(root->val);
        traverse(root->right, res);
    }

    // with stack
    vector<int> method2(TreeNode* root)
    {
        stack<TreeNode*> st{};
        vector<int> res{};
        TreeNode *cur = root;
        while (cur || !st.empty())
        {
            if (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};
