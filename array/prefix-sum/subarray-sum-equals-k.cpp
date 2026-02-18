#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int res = 0, prefix_sum = 0;
    unordered_map<int, int> map{{0, 1}};
    auto p = map.end();
    for (auto i : nums) {
      prefix_sum += i;
      p = map.find(prefix_sum - k);
      if (p != map.end()) {
        res += (*p).second;
      }
      map[prefix_sum]++;
    }
    return res;
  }
};
