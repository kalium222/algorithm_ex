#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        return method1(nums1, nums2, nums3, nums4);
    }

    int method1(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        int res = 0;
        unordered_map<int, int> umap1{};
        unordered_map<int, int> umap2{};
        for (auto a : nums1)
        {
            for (auto b : nums2)
            {
                umap1[a+b]++;
            }
        }
        for (auto c : nums3)
        {
            for (auto d : nums4)
            {
                umap2[c+d]++;
            }
        }
        for (auto p1 : umap1)
        {
            for (auto p2 : umap2)
            {
                if (p1.first+p2.first==0)
                {
                    res += p1.second * p2.second;
                }
            }
        }
        return res;
    }

    int method2(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        int res = 0;
        unordered_map<int, int> umap{};
        for (auto a : nums1)
        {
            for (auto b : nums2)
            {
                umap[a+b]++;
            }
        }
        for (auto c : nums3)
        {
            for (auto d : nums4)
            {
                auto p = umap.find(0-c-d);
                if (p!=umap.end())
                {
                    res += p->second;
                }
            }
        }
        return res;
    }
};
