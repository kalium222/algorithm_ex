#include <vector>
#include <queue>
using namespace std;

#include "Tree.hpp"

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        return method1(root);
    }

    // with queue
    vector<vector<int>> method1(TreeNode* root)
    {
        queue<TreeNode*> q{};
        vector<vector<int>> res{};
        if (!root) return res;
        else q.push(root);
        int temp_size;
        TreeNode *node;
        vector<int> v;
        while (!q.empty())
        {
            temp_size = q.size();
            for (; temp_size>0; temp_size--)
            {
                node = q.front();
                v.push_back(node->val);
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(std::move(v));
        }
        return res;
    }

    // recursively
    vector<vector<int>> method2(TreeNode* root)
    {
        vector<vector<int>> res{};
        traverse(root, 0, res);
        return res;
    }

    void traverse(TreeNode *cur, int depth, vector<vector<int>>& res)
    {
        if (!cur) return;
        while (res.size()<=depth) res.push_back(vector<int>());
        res[depth].push_back(cur->val);
        traverse(cur->left, depth+1, res);
        traverse(cur->right, depth+1, res);
    }
};
