#include <exception>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        int temp;
        stack<int> st;
        for (auto s : tokens)
        {
            if (s=="+"||s=="-"||s=="*"||s=="/")
            {
                temp = st.top();
                st.pop();
                if (s=="+") temp += st.top();
                else if (s=="-") temp = st.top() - temp;
                else if (s=="*") temp *= st.top();
                else if (s=="/") temp = st.top() / temp;
                else
                {
                    throw exception();
                }
                st.pop();
                st.push(temp);
            }
            else
            {
                temp = stoi(s);
                st.push(temp);
            }
        }
        return st.top();
    }

    // NOTE: try-catch is much slower than above
    int method1(vector<string>& tokens)
    {
        int temp;
        stack<int> st;
        for (auto s : tokens)
        {
            try
            {
                temp = stoi(s);
                st.push(temp);
            }
            catch (exception e)
            {
                temp = st.top();
                st.pop();
                if (s=="+") temp += st.top();
                else if (s=="-") temp = st.top() - temp;
                else if (s=="*") temp *= st.top();
                else if (s=="/") temp = st.top() / temp;
                else throw e;
                st.pop();
                st.push(temp);
            }
        }
        return st.top();
    }
};

int main(void)
{
    Solution sol{};
    vector<string> tokens = {"4","13","5","/","+"};
    sol.evalRPN(tokens);
    return 0;
}
