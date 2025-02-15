#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int search(vector<int>& nums, int target) {
        int head = 0, tail = nums.size();
        int index = tail/2;
        while (head <= tail)
        {
            if (nums[index] < target)
            {
                head = index+1;
                index = (head+tail)/2;
            }
            else if (nums[index] > target)
            {
                tail = index-1;
                index = (head+tail)/2;
            }
            else return index;
        }
        return -1;
    }

    // NOTE: 每个while研究[head, tail)区间
    int sovle1(vector<int>& nums, int target)
    {
        int head = 0, tail = nums.size();
        int index;
        while (head < tail)
        {
            index = (head+tail)/2;
            if (nums[index]>target)
            {
                tail = index;
            }
            else if (nums[index]<target)
            {
                head = index+1;
            }
            else return index;
        }
        return -1;
    }

    // NOTE: 每个while研究[left, right]区间
    int solve2(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size()-1;
        int index;
        while (left<=right)
        {
            index = (left+right)/2;
            if (nums[index]<target)
            {
                left = index+1;
            }
            else if (nums[index]>target)
            {
                right = index-1;
            }
            else return index;
        }
        return -1;
    }
};

int main(void)
{ 
    auto sol = Solution();
    vector<int> v = {-1, 0, 5};
    int target = -1;
    cout << sol.sovle1(v, target) << endl;
    return 0;
}

