#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int i, j;
    int temp;
    vector<vector<int>> res{};
    for (int h = 0; h < nums.size(); h++) {
      if (h >= 1 && nums[h] == nums[h - 1])
        continue;
      i = h + 1;
      j = nums.size() - 1;
      while (i < j) {
        temp = nums[i] + nums[j] + nums[h];
        if (temp == 0)
        {
          res.push_back({nums[h], nums[i], nums[j]});
          // NOTE:
          // don't forget this
          do i++; while (nums[i]==nums[i-1] && i<j);
          do j--; while (nums[j]==nums[j+1] && i<j);
        }
        else
          (temp > 0) ? j-- : i++;
      }
    }
    return res;
  }
};

int main(void) {
    Solution s{};
    auto l = vector<int>({-1,0,1,2,-1,-4});
    auto res = s.threeSum(l);
    for (auto v:res)
    {
        for (auto a : v)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
