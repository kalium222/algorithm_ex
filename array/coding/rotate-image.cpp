#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {}

  void method1(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int x, x_1, x_2, x_3;
    int y, y_1, y_2, y_3;
    int temp;
    if (n == 1)
      return;
    if (n % 2 == 0) {
      x = y = n / 2 - 1;
      x_1 = x;
      y_1 = y + 1;
      x_2 = x + 1;
      y_2 = y + 1;
      x_3 = x + 1;
      y_3 = y;
    } else {
      x = (n - 1) / 2;
      y = (n - 1) / 2 - 1;
      x_1 = x - 1;
      y_1 = y + 1;
      x_2 = x;
      y_2 = y + 2;
      x_3 = x + 1;
      y_3 = y + 1;
    }
    for (int i = 0; i <= x; i++) {
      for (int j = 0; j <= y; j++) {
        temp = matrix[x - i][y - j];
        matrix[x - i][y - j] = matrix[x_3 + j][y_3 - i];
        matrix[x_3 + j][y_3 - i] = matrix[x_2 + i][y_2 + j];
        matrix[x_2 + i][y_2 + j] = matrix[x_1 - j][y_1 + i];
        matrix[x_1 - j][y_1 + i] = temp;
      }
    }
  }

  // NOTE: fuck
  void method2(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int temp;
    for (int j = 0; j <= n / 2; j++) {
      for (int i = j; i < n - 1 - j; i++) {
        temp = matrix[i][j];
        matrix[i][j] = matrix[n - 1 - j][i];
        matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
        matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
        matrix[j][n - 1 - i] = temp;
      }
    }
  }

  void method3(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        swap(matrix[i][j], matrix[j][i]);

    for (auto line : matrix)
      reverse(line.begin(), line.end());
  }
};
