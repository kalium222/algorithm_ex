#include "Tree.hpp"
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        if (nums.size()==0) return nullptr;
        if (nums.size()==1)
        {
            return new TreeNode(*nums.begin());
        }
        TreeNode *root, *left, *right;
        auto p_max = max_element(nums.begin(), nums.end());
        root = new TreeNode(*p_max);
        auto left_nums = vector(nums.begin(), p_max);
        auto right_nums = vector(p_max+1, nums.end());
        left = left_nums.size()==0 ? nullptr : constructMaximumBinaryTree(left_nums);
        right = right_nums.size()==0 ? nullptr : constructMaximumBinaryTree(right_nums);
        root->left = left;
        root->right = right;
        return root;
    }
};
