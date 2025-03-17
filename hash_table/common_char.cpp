#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string>& words)
    {
        auto char_table = vector<int>(26, 1000000);
        for (auto s : words)
        {
            for (int i=0; i<26; i++)
            {
                char c = (char)('a'+i);
                int num = count(s.begin(), s.end(), c);
                char_table[i] = min(char_table[i], num);
            }
        }
        auto res = vector<string>();
        for (int i=0; i<26; i++)
        {
            for (int j=0; j<char_table[i]; j++)
            {
                string s(1, 'a'+i);
                res.push_back(s);
            }
        }
        return res;
    }
};

int main(void)
{
    Solution s{};
    vector<string> test = {"bella", "label", "roller"};
    s.commonChars(test);
    return 0;
}
