#include <vector>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    if (nums.size() <= 1)
      return nums;
    vector<int> res = {nums[0]};
    int i = 1, suffix_product = 1;
    int temp;

    while (i < nums.size()) {
      res.push_back(res[i - 1] * nums[i]);
      i++;
    }

    i = nums.size() - 1;
    while (i > 0) {
      temp = res[i];
      res[i] = suffix_product * res[i - 1];
      suffix_product *= nums[i];
      i--;
    }
    *res.begin() = suffix_product;

    return res;
  }
};

int main(void) {
  Solution s{};
  vector<int> v = {1, 2, 3, 4};
  s.productExceptSelf(v);
}
