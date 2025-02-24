#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        return this->solve1(target, nums);
    }

    int solve1(int target, vector<int>& nums)
    {
        if (nums.size()==0) return 0;
        int tail = 1, head = 0;
        int res = nums.size();
        int sum = nums[0];
        while (head<nums.size()&&tail<=nums.size())
        {
            if (sum<target)
            {
                if (tail==nums.size()) break;
                sum += nums[tail];
                tail++;
            }
            else
            {
                res = res<=(tail-head) ? res:(tail-head);
                sum -= nums[head];
                head++;
            }
        }
        if (head==0&&tail==nums.size()&&sum<target) return 0;
        return res;
    }

    int solve2(int target, vector<int>& nums)
    {
        int res = nums.size() + 1;
        int sum = 0;
        int head = 0;
        int l = 0;
        for (int tail=0; tail<nums.size(); tail++)
        {
            sum += nums[tail];
            while (sum >= target)
            {
                l = tail - head + 1;
                res = res < l ? res : l;
                sum -= nums[head++];
            }
        }
        return res == nums.size()+1 ? 0 : res;
    }
};

int main()
{
    auto s = Solution();
    vector<int> v = {2, 3, 1, 2, 4, 3};
    cout << s.minSubArrayLen(7, v) << endl;
    return 0;
}
