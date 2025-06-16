#pragma once

struct Tree
{
    int val;
    Tree *left;
    Tree *right;
    Tree() : val(0), left(nullptr), right(nullptr) {}
    Tree(int x) : val(x), left(nullptr), right(nullptr) {}
    Tree(int x, Tree *left, Tree *right) : val(x), left(left), right(right) {}
};
typedef Tree TreeNode;
void printTree(Tree* root);
