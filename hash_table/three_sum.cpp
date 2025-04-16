#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        return {};
    }

    // WARNING: time limit, although O(n^2)
    vector<vector<int>> method1(vector<int>& nums)
    {
        vector<vector<int>> res{};
        vector<int> temp;
        vector<vector<int>> temp_res;
        sort(nums.begin(), nums.end());
        for (auto p=nums.begin(); p!=nums.end(); p++)
        {
            if (*p>0) continue;
            if (p!=nums.begin() && *(p-1)==*p) continue;
            temp = vector<int>(p+1, nums.end());
            temp_res = twoSum(temp, -*p);
            for (auto& v : temp_res)
            {
                v.push_back(*p);
            }
            res.insert(res.end(), temp_res.begin(), temp_res.end());
        }
        return res;
    }
    vector<vector<int>> twoSum(vector<int>& nums, int target)
    {
        vector<vector<int>> res{};
        unordered_map<int, int> table{};
        for (int i=0; i<nums.size(); i++)
        {
            table[nums[i]]++;
            if (nums[i]*2==target)
            {
                if (table[nums[i]]==2)
                    res.push_back({nums[i], nums[i]});
                continue;
            }
            if (table[target-nums[i]]>0 && table[nums[i]]==1)
            {
                res.push_back({nums[i], target-nums[i]});
            }
        }
        return res;
    }

    vector<vector<int>> method2(vector<int>& nums)
    {
        vector<vector<int>> res{};
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]>0) break;
            if (i>0 && nums[i]==nums[i-1]) continue;
            int left = i+1;
            int right = nums.size()-1;
            while (left < right)
            {
                if (nums[i]+nums[left]+nums[right]>0) right--;
                else if (nums[i]+nums[left]+nums[right]<0) left++;
                else
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left<right && nums[left+1]==nums[left]) left++;
                    while (left<right && nums[right-1]==nums[right]) right--;
                    left++; right--;
                }
            }
        }
        return res;
    }
};

int main(void)
{
    Solution s{};
    vector<int> nums({1, 1, 1, 1, 4, 4, 4, 7, 7});
    sort(nums.begin(), nums.end());
    auto res = s.twoSum(nums, 8);
    for (auto v : res)
    {
        for (auto a : v)
        {
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}

