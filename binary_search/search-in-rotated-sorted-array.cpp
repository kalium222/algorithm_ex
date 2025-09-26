#include <vector>
using namespace std;

// TODO: leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int d = nums[0];
    if (d == target)
      return 0;
    int head = 0, tail = nums.size() - 1;
    int mid, m;
    while (head < tail) {
      mid = (head + tail) / 2;
      m = nums[mid];
      if (m < d) {
        if (target < m) {
          tail = mid;
        } else if (target == m) {
          return mid;
        } else if (target < d) {
          head = mid + 1;
        } else if (d < target) {
          tail = mid;
        }
      } else if (d < m) {
        if (target < d) {
          head = mid + 1;
        } else if (target < m) {
          tail = mid;
        } else if (target == m) {
          return mid;
        } else {
          head = mid + 1;
        }
      } else {
        if (target == nums[1])
          return 1;
        else
          return -1;
      }
    }
    return (nums[head] == target) ? head : -1;
  }
};
// NOTE:
// todo
