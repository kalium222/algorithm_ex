#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> s{};
        unordered_set<int> res{};
        for (auto i : nums1)
        {
            s.insert(i);
        }
        for (auto i : nums2)
        {
            if (s.find(i)!=s.end())
            {
                res.insert(i);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};

int main(void)
{
    vector<int> a{1, 2, 2, 1}, b{2, 2};
    Solution s{};
    auto res = s.intersection(a, b);
    for (auto i : res)
    {
        cout << i << ", ";
    }
    return 0;
}
