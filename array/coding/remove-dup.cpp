#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int l = nums.size();
    if (l <= 1)
      return l;
    int fast = 1, slow = 1;
    while (fast < l) {
      if (nums[fast - 1] == nums[fast]) {
        fast++;
        continue;
      }
      nums[slow++] = nums[fast++];
    }
    return slow + 1;
  }
};
