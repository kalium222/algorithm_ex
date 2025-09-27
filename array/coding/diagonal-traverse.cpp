#include <vector>
using namespace std;

// TODO:
// https://leetcode.com/problems/diagonal-traverse/

// NOTE:
// todo
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
    vector<int> res{};
    int m = mat[0].size() - 1, n = mat.size() - 1;
    int x_max, y_max;
    for (int dsum = 0; dsum <= m + n; dsum++) {
      x_max = dsum > m ? m : dsum;
      y_max = dsum > n ? n : dsum;
      if (dsum % 2 == 0) {
        for (int i = dsum - y_max; i <= x_max; i++) {
          res.push_back(mat[dsum - i][i]);
        }
      } else {
        for (int i = x_max; i >= dsum - y_max; i--) {
          res.push_back(mat[dsum - i][i]);
        }
      }
    }
    return res;
  }
};
