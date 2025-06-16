#include "Tree.hpp"
#include <queue>
#include <string>
#include <iostream>

void printTree(Tree* root) {
    if (!root) return;

    std::queue<Tree*> q;
    q.push(root);
    std::queue<int> posQ;  // 记录节点在当前层的打印位置
    posQ.push(20);         // 初始位置（可调整）

    int level = 0;
    while (!q.empty()) {
        int levelSize = q.size();
        std::vector<std::string> line(80, " ");  // 每行的字符串（假设宽度80）
        std::vector<std::string> branchLine(80, " ");

        for (int i = 0; i < levelSize; ++i) {
            Tree* node = q.front(); q.pop();
            int pos = posQ.front(); posQ.pop();

            // 打印当前节点
            std::string valStr = std::to_string(node->val);
            for (int j = 0; j < valStr.size(); ++j) {
                line[pos + j] = valStr[j];
            }

            // 处理左子节点
            if (node->left) {
                q.push(node->left);
                int leftPos = pos - 2;
                posQ.push(leftPos);
                branchLine[pos - 1] = "/";
            }

            // 处理右子节点
            if (node->right) {
                q.push(node->right);
                int rightPos = pos + 2 + valStr.size();
                posQ.push(rightPos);
                branchLine[pos + valStr.size()] = "\\";
            }
        }

        // 打印当前层
        for (const auto& s : line) std::cout << s;
        std::cout << "\n";
        for (const auto& s : branchLine) std::cout << s;
        std::cout << "\n";

        level++;
    }
}
