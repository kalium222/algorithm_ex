#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    return method2(nums, target);
  }

  // NOTE:
  // Ugly! redundent
  vector<int> method1(vector<int> &nums, int target) {
    unordered_map<int, int> map{};
    for (int i = 0; i < nums.size(); i++) {
      auto it = map.find(nums[i]);
      if (it != map.end() && target == 2 * nums[i])
        return {i, it->second};
      map.insert({nums[i], i});
    }
    for (int i = 0; i < nums.size(); i++) {
      auto it = map.find(target - nums[i]);
      if (it != map.end() && nums[i] != it->first)
        return {i, it->second};
    }
    return {};
  }

  auto method2(std::vector<int> &nums, int target) -> std::vector<int> {
    std::unordered_map<int, int> seen;
    for (int i = 0; i < (int)nums.size(); ++i) {
      if (auto it = seen.find(target - nums[i]); it != seen.end())
        return {it->second, i};
      seen.emplace(nums[i], i);
    }
    return {};
  }
};
