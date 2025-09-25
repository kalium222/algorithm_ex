// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
bool isBadVersion(int version) { return true; }

// TODO:
// given the number of versions.
// given the api isBadVersion
// all the versions after the first bad are bad
// find the first bad version
class Solution {
public:
  int firstBadVersion(int n) {
    unsigned int head = 0;
    unsigned int tail = n - 1;
    unsigned int mid;
    while (head < tail) {
      mid = (head + tail) / 2;
      if (isBadVersion(mid + 1)) {
        tail = mid;
      } else {
        head = mid + 1;
      }
    }
    return head + 1;
  }
};
// NOTE:
// use binary search template.
// head = 0; tail = n-1;
// vector[i] = i+1; to get version number
// make sure head <= mid <= tail
// and head <= target_index <= tail
