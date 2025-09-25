#include <vector>
using namespace std;

// TODO:
// given an array of int, _nums_, and a int _target_
// _nums_ is non-decreasingly ordered
// find the index of first and last occurency
// of _target_ in _nums_, return a vector of {a, b}
// if not exists, return {-1, -1}
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.empty())
      return {-1, -1};

    int head = 0;
    int tail = nums.size() - 1;
    int a, b, mid;
    while (head < tail) {
      mid = (head + tail) / 2;
      if (nums[mid] < target) {
        head = mid + 1;
      } else {
        tail = mid;
      }
    }
    a = (nums[head] == target) ? head : -1;

    head = 0;
    tail = nums.size() - 1;
    while (head < tail) {
      mid = 1 + (head + tail) / 2;
      if (nums[mid] <= target) {
        head = mid;
      } else {
        tail = mid - 1;
      }
    }
    b = (nums[head] == target) ? head : -1;

    return {a, b};
  }
};
// NOTE:
// todo
