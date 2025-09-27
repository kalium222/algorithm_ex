// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
  public:
    int get(int index);
    int length();
};


// TODO:
// https://leetcode.com/problems/find-in-mountain-array/
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        if (target==mountainArr.get(0)) return 0;
        return recur(1, mountainArr.length()-1, target, mountainArr);
    }

    bool isIncre(int tail, MountainArray &mountainArr) {
        return mountainArr.get(tail) > mountainArr.get(tail-1);
    }

    bool isDecre(int head, MountainArray &mountainArr) {
        return mountainArr.get(head) > mountainArr.get(head+1);
    }

    int recur(int head, int tail, int target, MountainArray &mountainArr) {
        if (head>=tail) 
            return (target==mountainArr.get(head)) ? head : -1;
        int mid = (head+tail)/2;
        if (target>mountainArr.get(mid)) {
            if (mountainArr.get(mid-1)<mountainArr.get(mid)
            && mountainArr.get(mid)<mountainArr.get(mid+1)) {
                return recur(mid+1, tail, target, mountainArr);
            }
            else if (mountainArr.get(mid-1)>mountainArr.get(mid)
            && mountainArr.get(mid)>mountainArr.get(mid+1)) {
                return recur(head, mid, target, mountainArr);
            }
            else {
                int left = recur(head, mid, target, mountainArr);
                return left==-1 ? recur(mid+1, tail, target, mountainArr) : left;
            }
        } else if (target < mountainArr.get(mid)) {
            if (isIncre(tail, mountainArr)) {
                return recur(head, mid, target, mountainArr);
            } else if (isDecre(head, mountainArr)) {
                return recur(mid+1, tail, target, mountainArr);
            } 
            int left = recur(head, mid, target, mountainArr);
            return left==-1 ? recur(mid+1, tail, target, mountainArr) : left;
        } else {
            return mid;
        }
    }
};
// NOTE: this is not fast enough to pass all the tests
