#include <vector>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char>& s)
    {
        char temp;
        int l = s.size();
        for (int i=0; i<l/2; i++)
        {
            swap(s[i], s[l-1-i]);
        }
    }
};
