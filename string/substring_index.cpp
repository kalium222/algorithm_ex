#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int res = -1;
        auto pre_l = prefix_function(needle);
        int i = 0, j = 0;
        while (j<haystack.size() && j-i<needle.size())
        {
            if (haystack[j]==needle[j-i])
            {
                j++;
            }
            else if (i==j)
            {
                j++;
                i = j;
            }
            else
            {
                i = j - pre_l[j-i-1];
            }
        }
        if (j-i==needle.size()) res = i;
        return res;
    }

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
    string s = "mississippi";
    string p = "issip";
    cout << sol.strStr(s, p) << endl;
    return 0;
}
