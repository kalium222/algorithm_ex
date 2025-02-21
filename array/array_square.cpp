#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        auto res = vector<int>(nums.size(), 0);
        int head = 0, tail = nums.size()-1;
        int ind = nums.size()-1;
        int p = nums.size()-1;
        while (head<=tail)
        {
            if (abs(nums[head])<=abs(nums[tail]))
            {
                res[ind] = nums[tail] * nums[tail];
                ind--;
                tail--;
            }
            else
            {
                res[ind] = nums[head] * nums[head];
                ind--;
                head++;
            }
        }
        return res;
    }
};
