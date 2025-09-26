#include <vector>
using namespace std;

// TODO:
// leetcode.com/problems/find-peak-element/
class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int head = 0, tail = nums.size() - 1;
    if (head == tail)
      return head;
    if (head == tail + 1)
      return (nums[0] > nums[1]) ? 0 : 1;
    if (nums[0] > nums[1])
      return 0;
    if (nums[tail] > nums[tail - 1])
      return tail;
    head = 1, tail = nums.size() - 2;
    int mid;
    while (head < tail) {
      mid = (head + tail) / 2;
      if (nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid]) {
        return mid;
      } else if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]) {
        head = mid + 1;
      } else if (nums[mid - 1] > nums[mid] && nums[mid] > nums[mid + 1]) {
        tail = mid;
      } else {
        head = mid + 1;
      }
    }
    return head;
  }
};
