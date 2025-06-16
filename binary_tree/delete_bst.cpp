#include "Tree.hpp"
#include <exception>
#include <utility>

class Solution
{
public:
    // NOTE: Man! What can I say
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (!root) return nullptr;
        if (!root->left && !root->right && root->val==key) return nullptr;
        auto cur = root;
        TreeNode* prev = nullptr;
        while (cur)
        {
            if (cur->val > key)
            {
                prev = cur;
                cur = cur->left;
            }
            else if (cur->val < key)
            {
                prev = cur;
                cur = cur->right;
            }
            else
            {
                if (cur==root && (!cur->left != !cur->right))
                {
                    return cur->left ? cur->left : cur->right;
                }
                _delete_node(prev, cur);
                break;
            }
        }
        return root;
    }

    void _delete_node(TreeNode* parent, TreeNode* node)
    {
        if (!node) return;
        else if (!node->right && !node->left)
        {
            if (parent->left == node) parent->left = nullptr;
            else parent->right = nullptr;
            return;
        }
        else if (node->left && node->right)
        {
            auto res = _find_suc(node);
            node->val = res.first->val;
            _delete_node(res.second, res.first);
        }
        else if (node->left)
        {
            if (parent->left==node) parent->left = node->left;
            else parent->right = node->left;
        }
        else
        {
            if (parent->left==node) parent->left = node->right;
            else parent->right = node->right;
        }
    }

    std::pair<TreeNode*, TreeNode*> _find_suc(TreeNode* root)
    {
        if (!root || !root->right)
        {
            throw std::exception();
        }
        auto cur = root->right;
        auto prev = root;
        while (cur->left)
        {
            prev = cur;
            cur = cur->left;
        }
        return std::make_pair(cur, prev);
    }
};

int main(void)
{
    TreeNode n0(2);
    TreeNode n1(1);
    TreeNode n2(3);
    TreeNode n3(5);
    TreeNode n4(4);
    TreeNode n5(6);
    n0.left = &n1;
    n0.right = &n2;
    n2.right = &n3;
    n3.left = &n4;
    n3.right = &n5;
    printTree(&n0);
    Solution s{};
    s.deleteNode(&n0, 3);
    printTree(&n0);
    return 0;
}
