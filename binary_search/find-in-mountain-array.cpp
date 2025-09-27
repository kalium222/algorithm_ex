// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
  public:
    int get(int index);
    int length();
};


// TODO:
// https://leetcode.com/problems/find-in-mountain-array/

// NOTE: this is not fast enough to pass all the tests
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

// NOTE: this is enough
class Solution2 {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeak(mountainArr);
        if (target>mountainArr.get(peak)) return -1;
        if (target==mountainArr.get(peak)) return peak;
        int left_res = bsearch(target, 0, peak-1, mountainArr, false);
        return left_res!=-1 ? left_res : bsearch(target, mountainArr.length()-1, peak + 1, mountainArr, true);
    }

    int findPeak(MountainArray &mountainArr) {
        int head = 1, tail = mountainArr.length() - 2;
        int mid;
        while (head<tail) {
            mid = (head+tail)/2;
            if (mountainArr.get(mid)>mountainArr.get(mid+1)) {
                tail = mid;
            } else {
                head = mid + 1;
            }
        }
        return head;
    }

    int bsearch(int target, int head, int tail, MountainArray &mountainArr, bool reversed) {
        int mid;
        int m;
        while (head!=tail) {
            mid = (head+tail)/2;
            mid = reversed ? mid + 1 : mid;
            m = mountainArr.get(mid);
            if (m>target) {
                tail = mid;
            } else if (m==target) {
                return mid;
            } else {
                head = reversed ? mid - 1 : mid + 1;
            }
        }
        if (mountainArr.get(head)==target) return head;
        else return -1;
    }
};
