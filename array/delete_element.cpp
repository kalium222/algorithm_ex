#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        return solve2(nums, val);
    }

    // NOTE: 若nums[i]==val, 则移到末尾
    int solve1(vector<int>& nums, int val)
    {
        int index = 0;
        int rep_id = nums.size()-1;
        while (index<=rep_id)
        {
            if (nums[rep_id]==val)
            {
                rep_id--;
            }
            else if (nums[index]!=val)
            {
                index++;
                continue;
            }
            else
            {
                nums[index] = nums[rep_id];
                nums[rep_id] = val;
                rep_id--;
            }
        }
        return rep_id+1;
    }

    // NOTE: 若nums[i]!=val, 则移到开头
    int solve2(vector<int>& nums, int val)
    {
        int ind = 0;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]!=val)
            {
                nums[ind] = nums[i];
                ind++;
            }
        }
        return ind;
    }
};
