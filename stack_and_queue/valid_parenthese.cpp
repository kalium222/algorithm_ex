#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto c : s)
        {
            // NOTE: 
            // if (c==')' || c==']' || c=='}')
            // {
            //     if (st.empty()) return false;
            //     else if (c==')')...
            // }
            // else
            // {
            //     st.push(c);
            // }
            if (c=='(') st.push(')');
            else if (c=='[') st.push(']');
            else if (c=='{') st.push('}');
            else if (st.empty() || st.top()!=c) return false;
            else st.pop();
        }
        return st.empty();
    }
};
