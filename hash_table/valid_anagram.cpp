#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        auto char_table = vector<int>(26, 0);
        for (auto c : s)
        {
            char_table[(int)c-(int)'a']++;
        }
        for (auto c : t)
        {
            char_table[(int)c-(int)'a']--;
        }
        for (auto i :  char_table)
        {
            if (i!=0) return false;
        }
        return true;
    }
};
