#include <algorithm>
#include <stack>
#include <cmath>
#include "Tree.hpp"

class Solution
{
public:
    bool isBalanced(TreeNode* root)
    {
        return recur(root).second;
    }

    std::pair<int, bool> recur(TreeNode *root)
    {
        if (!root)
        {
            return std::pair(0, true);
        }
        else
        {
            int h;
            bool balanced;
            auto l = recur(root->left);
            auto r = recur(root->right);
            if (!l.second || !r.second)
                return std::pair(0, false);
            h = 1 + std::max(l.first, r.first);
            balanced = std::abs(l.first-r.first) <= 1;
            balanced = balanced && l.second && r.second;
            return std::pair(h, balanced);
        }
    }

    bool method2(TreeNode* root) {
        std::stack<std::pair<TreeNode*, int>> stk; // {node, visited: 0/1}
        stk.push({root, 0});
        bool balanced = true;
        int leftHeight = 0, rightHeight = 0;

        while (!stk.empty()) {
            auto [node, visited] = stk.top();
            stk.pop();

            if (!node) {
                // 空节点，高度为 0
                continue;
            }

            if (visited == 0) {
                // 第一次访问，压栈（后序：左 → 右 → 根）
                stk.push({node, 1}); // 标记为已访问
                stk.push({node->right, 0});
                stk.push({node->left, 0});
            } else {
                // 第二次访问（后序处理）
                leftHeight = node->left ? node->left->val : 0; // 假设我们修改 val 存储高度
                rightHeight = node->right ? node->right->val : 0;

                if (abs(leftHeight - rightHeight) > 1) {
                    balanced = false;
                    break; // 提前终止迭代
                }

                node->val = 1 + std::max(leftHeight, rightHeight); // 存储当前高度
            }
        }

        return balanced;
    }
};
