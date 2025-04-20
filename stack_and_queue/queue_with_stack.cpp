#include <stack>

class MyQueue
{
    std::stack<int> holder;
    std::stack<int> exchanger;
public:
    MyQueue() {}
    
    void push(int x)
    {
        int temp;
        while (!holder.empty())
        {
            temp = holder.top();
            holder.pop();
            exchanger.push(temp);
        }
        holder.push(x);
        while (!exchanger.empty())
        {
            temp = exchanger.top();
            exchanger.pop();
            holder.push(temp);
        }
    }
    
    int pop()
    {
        int temp = holder.top();
        holder.pop();
        return temp;
    }
    
    int peek()
    {
        return holder.top();
    }
    
    bool empty() {
        return holder.empty();
    }
};
