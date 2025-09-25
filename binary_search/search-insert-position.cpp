#include <vector>
using namespace std;

// TODO:
// given a sorted array of int, _nums_, and a _target_
// return the index of that target.
// if not exists, return the index
// where it would be if it were inserted in order.
class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int head = 0;
    int tail = nums.size() - 1;
    if (tail == 0) {
      return target > nums[head] ? 1 : 0;
    }
    if (target > nums[tail]) {
      return tail + 1;
    }
    int mid;
    while (head < tail) {
      mid = (head + tail) / 2;
      if (nums[mid] < target) {
        head = mid + 1;
      } else if (nums[mid] > target) {
        tail = mid;
      } else {
        return mid;
      }
    }
    return head;
  }
};
// NOTE:
// 1. basically same as find smallest letter
// greater than target
