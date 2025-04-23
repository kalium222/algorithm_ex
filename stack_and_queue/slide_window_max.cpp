#include <iostream>
#include <limits>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
    class MonoQueue
    {
        deque<int> que{};
    public:
        void pop_front(const int &x)
        {
            if (!que.empty() && x==que.front())
                que.pop_front();
        }

        void push_back(const int &x)
        {
            while (!que.empty() && que.back()<x)
            {
                que.pop_back();
            }
            que.push_back(x);
        }

        int front()
        {
            return que.front();
        }
    };

public:
    // directly use monoque class
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        MonoQueue monoque{};
        vector<int> res{};
        for (int i=0; i<k; i++)
        {
            monoque.push_back(nums[i]);
        }
        res.push_back(monoque.front());
        for (int i=1; i+k-1<nums.size(); i++)
        {
            monoque.pop_front(nums[i]);
            monoque.push_back(nums[i+k-1]);
            res.push_back(monoque.front());
        }
        return res;
    }

    // NOTE: too much redundent code
    vector<int> method1(vector<int>& nums, int k)
    {
        deque<int> monoque{};
        vector<int> res{};
        for (int i=0; i<k; i++)
        {
            if (monoque.empty()) monoque.push_back(nums[i]);
            else if (nums[i]<monoque.back())
            {
                monoque.push_back(nums[i]);
            }
            else
            {
                while (!monoque.empty() && monoque.back()<nums[i])
                {
                    monoque.pop_back();
                }
                monoque.push_back(nums[i]);
            }
        }
        res.push_back(monoque.front());
        for (int i=1; i+k-1<nums.size(); i++)
        {
            if (nums[i-1]==monoque.front())
            {
                monoque.pop_front();
            }
            if (nums[i+k-1]>monoque.front())
            {
                monoque.clear();
                monoque.push_back(nums[i+k-1]);
            }
            else
            {
                while (!monoque.empty() && monoque.back()<nums[i+k-1])
                {
                    monoque.pop_back();
                }
                monoque.push_back(nums[i+k-1]);
            }
            res.push_back(monoque.front());
        }
        return res;
    }

    // WARNING: wrong
    vector<int> method2(vector<int>& nums, int k)
    {
        int min_int = numeric_limits<int>::min();
        int first = min_int;
        int second = first;
        vector<int> res = {};
        for (int i=0; i<k; i++)
        {
            if (nums[i]>=first)
            {
                second = min_int;
                first = nums[i];
            }
            else if (nums[i]>=second)
            {
                second = nums[i];
            }
        }
        res.push_back(first);
        for (int i=1; i+k-1<nums.size(); i++)
        {
            // pop
            if (nums[i-1]==first)
            {
                first = second;
                second = min_int;
            }
            // push
            if (nums[i+k-1]>first)
            {
                second = min_int;
                first = nums[i+k-1];
            }
            else if (nums[i+k-1]>=second)
            {
                // WARNING: cannot find second in this way.
                // must use a monoqueue
                second = nums[i+k-1];
            }
            res.push_back(first);
        }
        return res;
    }
};

int main(void)
{
    vector<int> v = {-6,-10,-7,-1,-9,9,-8,-4,10,-5,2,9,0,-7,7,4,-2,-10,8,7};
    Solution sol{};
    auto res = sol.method1(v, 7);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
