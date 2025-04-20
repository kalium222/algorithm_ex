#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());
        removeRedundentSpaces(s);
        int fast = 0, slow = 0;
        while (fast<s.size())
        {
            if (s[fast]==' ')
            {
                reverse(s.begin()+slow, s.begin()+fast);
                fast++;
                slow = fast;
            }
            else
            {
                fast++;
            }
        }
        reverse(s.begin()+slow, s.end());
        return s;
    }

    void removeRedundentSpaces(string& s)
    {
        int fast = 0, slow = 0;
        while (fast < s.size() && s[fast]==' ') fast++;
        while (fast < s.size())
        {
            if (s[fast]==' ' && s[fast-1]==' ')
            {
                fast++;
            }
            else
            {
                s[slow] = s[fast];
                fast++;
                slow++;
            }
        }
        if (s[slow-1]==' ') slow--;
        s.resize(slow);
    }
};

int main(void)
{
    Solution sol{};
    string s = "  hello world  ";
    cout << s << endl;
    cout << sol.reverseWords(s) << endl;
    return 0;
}
