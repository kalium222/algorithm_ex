#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int t = 0, l = 0;
        int r = matrix[0].size() - 1, b = matrix.size() - 1;
        vector<int> res{};
        while (t<=b && l<=r) {
            if (t==b) {
                for (int i=l; i<=r; i++)
                    res.push_back(matrix[t][i]);
            } else if (l==r) {
                for (int i=t; i<=b; i++)
                    res.push_back(matrix[i][l]);
            } else {
                for (int i=l; i<r; i++) 
                    res.push_back(matrix[t][i]);
                for (int i=t; i<b; i++)
                    res.push_back(matrix[i][r]);
                for (int i=r; i>l; i--)
                    res.push_back(matrix[b][i]);
                for (int i=b; i>t; i--)
                    res.push_back(matrix[i][l]);
            }
            t++; b--;
            l++; r--;
        }
        return res;
    }
};
