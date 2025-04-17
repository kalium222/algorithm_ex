#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> res{};
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++)
        {
            for (int j=i+1; j<nums.size(); j++)
            {
                if (nums[i]>0 && nums[i]+nums[j]>target) break;
                if (i>0 && nums[i]==nums[i-1]) continue;
                if (j>i+1 && nums[j]==nums[j-1]) continue;
                int left = j+1, right = nums.size()-1;
                long sum;
                while(left < right)
                {
                    sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum>target) right--;
                    else if (sum<target) left++;
                    else
                    {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left<right && nums[left+1]==nums[left]) left++;
                        while (left<right && nums[right-1]==nums[right]) right--;
                        left++; right--;
                    }
                }
            }
        }
        return res;
    }
};

int main(void)
{
    Solution s{};
    vector<int> v{1,-2,-5,-4,-3,3,3,5};
    s.fourSum(v, -11);
    return 0;
}
