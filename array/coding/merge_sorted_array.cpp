#include <vector>
using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    auto v1 = vector(nums1.begin(), nums1.begin() + m);
    auto v2 = vector(nums2.begin(), nums2.begin() + n);
    auto p1 = v1.begin();
    auto p2 = v2.begin();
    auto p = nums1.begin();

    while (p1 != v1.end() || p2 != v2.end()) {
      if (p1 != v1.end() && p2 != v2.end()) {
        auto &smaller_p = *p1 < *p2 ? p1 : p2;
        *p = *smaller_p;
        p++;
        smaller_p++;
      } else {
        auto &valid_p = (p1 != v1.end()) ? p1 : p2;
        *p = *valid_p;
        p++;
        valid_p++;
      }
    }
    return;
  }
};
