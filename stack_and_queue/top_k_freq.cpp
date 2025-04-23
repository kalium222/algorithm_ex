#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public: 
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        return method2(nums, k);
    }

    // directly sort it
    vector<int> method1(vector<int>& nums, int k)
    {
        unordered_map<int, int> table{};
        vector<int> res{};
        for (auto i : nums)
        {
            table[i]++;
        }
        vector<pair<int, int>> sorted(table.begin(), table.end());
        sort(sorted.begin(), sorted.end(), [](pair<int, int> a, pair<int, int> b){
                return a.second > b.second;
                });
        for (auto it=sorted.begin(); it!=sorted.end() && k>0; it++, k--)
        {
            res.push_back(it->first);
        }
        return res;
    }

    class pair_less
    {
        using p = pair<int, int>;
    public:
        bool operator()(const p &a, const p &b)
        {
            return a.second < b.second;
        }
    };
    // with heap
    vector<int> method2(vector<int>& nums, int k)
    {
        unordered_map<int, int> table{};
        priority_queue<pair<int, int>, vector<pair<int, int>>, pair_less> pri_que{};
        vector<int> res{};
        for (auto i : nums)
        {
            table[i]++;
        }
        for (auto p : table)
        {
            pri_que.push(p);
        }
        for (int i=0; i<k; i++)
        {
            res.push_back(pri_que.top().first);
            pri_que.pop();
        }
        return res;
    }
};

int main(void)
{
    Solution sol{};
    vector<int> v = {1,1,1,2,2,3};
    sol.topKFrequent(v, 2);
    return 0;
}
