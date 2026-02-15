#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> set1 = unordered_set(nums1.begin(), nums1.end());
    unordered_set<int> set2 = unordered_set(nums2.begin(), nums2.end());
    vector<int> res{};
    for (auto i : set2) {
      if (set1.find(i) != set1.end()) {
        res.push_back(i);
      }
    }
    return res;
  }
};
