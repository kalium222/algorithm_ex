#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> m{};
        for (int i=0; i<nums.size(); i++)
        {
            auto p = m.find(target-nums[i]);
            if (p==m.end())
            {
                m.insert({nums[i], i});
            }
            else
            {
                return vector<int>({i, p->second});
            }
        }
        return {};
    }
};
