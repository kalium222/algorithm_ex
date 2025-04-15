#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> table(26, 0);
        int temp;
        for (char c : magazine)
        {
            temp = (int)(c-'a')%26;
            table[temp]++;
        }
        for (char c : ransomNote)
        {
            temp = (int)(c-'a')%26;
            table[temp]--;
            if (table[temp]<0)
            {
                return false;
            }
        }
        return true;
    }
};
