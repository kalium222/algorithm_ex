#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> prefix_function(string s)
    {
        vector<int> res(s.size());
        int pre_l;
        for (int i=1; i<res.size(); i++)
        {
            pre_l = res[i-1];
            while (pre_l>0 && s[i]!=s[pre_l])
            {
                pre_l = res[pre_l-1];
            }
            if (s[i]==s[pre_l]) pre_l++;
            res[i] = pre_l;
        }
        return res;
    }
};

int main(void)
{
    Solution sol{};
    auto res = sol.prefix_function("acaceacacb");
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
