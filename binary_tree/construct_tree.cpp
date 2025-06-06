#include "Tree.hpp"
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if (inorder.size()==0) return nullptr;

        TreeNode *root, *left, *right;
        int root_val = postorder.back();
        root = new TreeNode(root_val);

        auto p_in = find(inorder.begin(), inorder.end(), root_val);
        auto left_in = vector<int>(inorder.begin(), p_in);
        auto right_in = vector<int>(p_in+1, inorder.end());
        auto p_post = postorder.begin() + left_in.size();
        auto left_post = vector<int>(postorder.begin(), p_post);
        auto right_post = vector<int>(p_post, postorder.end()-1);

        if (left_in.size()==0)
            left = nullptr;
        else
            left = buildTree(left_in, left_post);
        if (right_in.size()==0)
        {
            right = nullptr;
        }
        else
        {
            right = buildTree(right_in, right_post);
        }
        root->left = left;
        root->right = right;
        return root;
    }
};

int main(void)
{
    Solution s{};
    vector<int> v1 = {9,3,15,20,7};
    vector<int> v2 = {9,15,7,20,3};
    s.buildTree(v1, v2);
    return 0;
}
