#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool checkSubarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> m{{0, -1}};
    int prefix_sum = 0;
    auto p = m.end();

    for (int i = 0; i < nums.size(); i++) {
      prefix_sum += nums[i];
      p = m.find(prefix_sum % k);
      if (p != m.end()) {
        if (i - p->second >= 2) {
          return true;
        }
      } else {
        m[prefix_sum % k] = i;
      }
    }
    return false;
  }
};
