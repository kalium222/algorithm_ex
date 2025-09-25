#include <vector>
using namespace std;

// TODO:
// given a char _target_ and a vector of chars _letters_
// letters is non-decreasingly ordered
// and at least two different char are in letters
// find the smallest char that greater than target
// if not exists, return the first element
class Solution {
public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    int head = 0;
    int tail = letters.size() - 1;
    if (target >= letters[tail])
      return letters[head];
    int mid;
    while (head < tail) {
      mid = (head + tail) / 2;
      if (target < letters[mid]) {
        tail = mid;
      } else {
        head = mid + 1;
      }
    }
    return letters[head];
  }
};
// NOTE:
// 1. of course binary-search
// 2. how to stop?
// 3. special cases?
//    target is larger than the max(letters). Just check
// 4. why at least two different char?
//    doesn't fucking matter
// 根本就不会啊, 根本就是乱写一通然后瞎几把解释一下
