#include <vector>
#include <string>
using namespace std;

#include "Tree.hpp"


class Solution
{
public:
    // NOTE: why is not so efficient as I thought?
    vector<string> binaryTreePaths(TreeNode *root)
    {
        auto cur = root;
        auto temp = root;
        vector<string> res{};
        vector<TreeNode*> path{};
        while (cur)
        {
            if (cur->left)
            {
                temp = cur->left;
                while (temp->right && temp->right!=cur)
                    temp = temp->right;
                if (!temp->right)
                {
                    temp->right = cur;
                    path.push_back(cur);
                    cur = cur->left;
                }
                else
                {
                    temp->right = nullptr;
                    if (!temp->left)
                        res.push_back(getPathString(path));
                    while (path.back()!=cur)
                        path.pop_back();
                    cur = cur->right;
                }
            }
            else
            {
                path.push_back(cur);
                cur = cur->right;
            }
        }
        cur = root;
        while (cur->right)
            cur = cur->right;
        if (!cur->right && !cur->left)
            res.push_back(getPathString(path));
        return res;
    }

    string getPathString(vector<TreeNode*> path)
    {
        int s = path.size();
        string res{};
        for (int i=0; i<s; i++)
        {
            res += to_string(path[i]->val);
            if (i<s-1)
                res += "->";
        }
        return res;
    }
};
