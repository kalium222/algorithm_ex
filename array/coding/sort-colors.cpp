#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int a, b, c;
    a = b = c = 0;
    for (auto i : nums) {
      switch (i) {
      case 0:
        a++;
        break;
      case 1:
        b++;
        break;
      case 2:
        c++;
        break;
      default:
        break;
      }
    }
    fill(nums.begin(), nums.begin() + a, 0);
    fill(nums.begin() + a, nums.begin() + a + b, 1);
    fill(nums.begin() + a + b, nums.begin() + a + b + c, 2);
  }
};
