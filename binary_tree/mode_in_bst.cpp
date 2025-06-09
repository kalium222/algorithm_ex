#include "Tree.hpp"
#include <vector>
#include <stack>

class Solution
{
public:
    std::vector<int> findMode(TreeNode* root)
    {
        return method1(root);
    }

    std::vector<int> method1(TreeNode* root)
    {
        auto cur = root;
        auto temp = root;
        TreeNode *prev = nullptr;
        int count = 1, max_count = 0;
        std::vector<int> res{};

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
                    traverse(prev, cur, count, max_count, res);
                    cur = cur->right;
                }
            }
            else
            {
                traverse(prev, cur, count, max_count, res);
                cur = cur->right;
            }
        }
        traverse(prev, cur, count, max_count, res);
        return res;
    }

    std::vector<int> method2(TreeNode* root)
    {
        std::stack<TreeNode*> st{};

        auto cur = root;
        TreeNode *prev = nullptr;
        int count = 1, max_count = 0;
        std::vector<int> res{};

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
                traverse(prev, cur, count, max_count, res);
                cur = cur->right;
            }
        }
        traverse(prev, cur, count, max_count, res);
        return res;
    }

    void traverse(TreeNode *&prev, TreeNode *cur,
            int &count, int &max_count, std::vector<int> &res)
    {
        if (!prev)
        {
            count = 1;
            prev = cur;
        }
        else if (!cur || prev->val!=cur->val)
        {
            if (count > max_count)
            {
                max_count = count;
                res.clear();
                res.push_back(prev->val);
            }
            else if (count == max_count)
            {
                res.push_back(prev->val);
            }
            count = 1;
        }
        else
        {
            count++;
        }
        prev = cur;
    }
};
