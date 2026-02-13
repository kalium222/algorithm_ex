#include <vector>
using namespace std;

// TODO:
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
  int findMin(vector<int> &nums) {
    int head = 0;
    int tail = nums.size() - 1;
    if (nums[head] < nums[tail])
      return nums[head];
    int d = nums[head];
    int mid;
    while (head < tail) {
      mid = (head + tail) / 2;
      if (nums[mid] < d) {
        tail = mid;
      } else {
        head = mid + 1;
      }
    }
    return nums[head];
  }
};
// NOTE:
// todo
