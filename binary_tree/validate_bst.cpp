#include "Tree.hpp"
#include <iostream>
#include <stack>
#include <limits>

class Solution
{
public:
    bool isValidBST(TreeNode* root)
    {
        return method2(root);
    }

    // NOTE: Wrong!
    bool method1(TreeNode* root)
    {
        if (!root) return true;
        else if (!root->left && !root->right) return true;
        bool res = true;
        if (root->left)
            res &= (root->val > root->left->val) &&
                isValidBST(root->left);
        if (root->right)
            res &= (root->val < root->right->val) &&
                isValidBST(root->right);
        return res;
    }

    // NOTE: DEADSIGNAL in leetcode server. don't know why
    bool method2(TreeNode *root)
    {
        auto cur = root;
        auto temp = root;
        long val = (long)std::numeric_limits<int>::min() - 1;
        while (cur)
        {
            if ((temp = cur->left))
            {
                while (temp->right && temp->right!=cur)
                    temp = temp->right;
                if (!temp->right)
                {
                    temp->right = cur;
                    cur = cur->left;
                }
                else
                {
                    temp->right = nullptr;
                    if (cur->val > val) val = cur->val;
                    else return false;
                    cur = cur->right;
                }
            }
            else
            {
                if (cur->val > val) val = cur->val;
                else return false;
                cur = cur->right;
            }
        }
        return true;
    }

    bool method3(TreeNode* root)
    {
        std::stack<TreeNode*> st{};
        long val = (long)std::numeric_limits<int>::min() - 1;
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
                if (cur->val>val) val = cur->val;
                else return false;
                cur = cur->right;
            }
        }
        return true;
    }
};

int main(void)
{
    Solution s{};
    TreeNode *n0 = new TreeNode(5);
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(4);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(6);
    n0->left = n1;
    n0->right = n2;
    n2->left = n3;
    n2->right = n4;
    auto res = s.method2(n0);
    std::cout << res << std::endl;
    return 0;
}
