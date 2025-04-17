#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string reverseString(string s, int k)
    {
        for (int i=0; i<s.size()-1; i+=2*k)
        {
            if (i+k < s.size())
            {
                reverse(s.begin()+i, s.begin()+i+k);
            }
            else
            {
                reverse(s.begin()+i, s.end());
            }
        }
        return s;
    }
};
