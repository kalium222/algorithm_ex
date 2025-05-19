#include <algorithm>
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
    vector<int> postorderTraversal(TreeNode* root)
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
        traverse(root->right, res);
        res.push_back(root->val);
    }

    // with stack
    vector<int> method2(TreeNode* root)
    {
        stack<TreeNode*> st{};
        vector<int> res{};
        if (!root) return res;
        st.push(root);
        TreeNode *temp;
        while (!st.empty())
        {
            temp = st.top();
            st.pop();
            res.push_back(temp->val);
            if (temp->left) st.push(temp->left);
            if (temp->right) st.push(temp->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // with stack
    vector<int> method3(TreeNode* root)
    {
        stack<TreeNode*> st{};
        vector<int> res{};
        TreeNode *cur = root;
        TreeNode *prev = nullptr;
        while (cur || !st.empty())
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if (cur->right && cur->right!=prev)
            {
                st.push(cur);
                cur = cur->right;
            }
            else
            {
                res.push_back(cur->val);
                prev = cur;
                cur = nullptr;
            }
        }
        return res;
    }

    // morris
    vector<int> method4(TreeNode *root)
    {
        // 不会
        vector<int> res;
        TreeNode dump(0);
        dump.left = root;
        TreeNode *cur = &dump;
        while (cur) {
            if (cur->left == nullptr) {
                cur = cur->right;
            } else {
                TreeNode *prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                if (prev->right == nullptr) {
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    // 反转从 cur->left 到 prev 的路径
                    TreeNode *start = cur->left;
                    vector<int> tmp;
                    while (start != prev) {
                        tmp.push_back(start->val);
                        start = start->right;
                    }
                    tmp.push_back(prev->val);
                    reverse(tmp.begin(), tmp.end());
                    for (int num : tmp) {
                        res.push_back(num);
                    }
                    prev->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};
