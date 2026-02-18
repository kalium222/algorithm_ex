#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    int prefix_sum = 0, res = 0;
    unordered_map<int, int> m = {{-1, -1}};
    auto p = m.end();
    int temp;
    for (int i = 0; i < nums.size(); i++) {
      prefix_sum += nums[i];
      temp = i - 2 * prefix_sum;
      p = m.find(temp);
      if (p != m.end()) {
        res = max(res, i - p->second);
      } else
        m[temp] = i;
    }
    return res;
  }
};

int main(void) {
  vector<int> v = {0, 1, 1, 1, 1, 1, 0, 0, 0};
  Solution s{};
  s.findMaxLength(v);
  return 0;
}
