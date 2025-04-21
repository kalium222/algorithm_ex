#include <queue>

class MyStack
{
    std::queue<int> q;
public:
    MyStack() {}
    
    void push(int x)
    {
        q.push(x);
    }
    
    int pop()
    {
        int n = (int)q.size();
        int temp;
        for (int i=0; i<n-1; i++)
        {
            temp = q.front();
            q.pop();
            q.push(temp);
        }
        temp = q.front();
        q.pop();
        return temp;
    }
    
    int top()
    {
        return q.back();
    }
    
    bool empty()
    {
        return q.empty();
    }
};
