#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    auto h = numbers.begin();
    auto t = numbers.end() - 1;
    while (h < t) {
      if (*h + *t > target) {
        t--;
      } else if (*h + *t < target) {
        h++;
      } else {
        return {int(h - numbers.begin()) + 1, int(t - numbers.begin()) + 1};
      }
    }
    return {};
  }
};
