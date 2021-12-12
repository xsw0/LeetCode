class MinStack
{
    stack<pair<int, int>> l;

public:
    MinStack()
    {

    }

    void push(int val)
    {
        auto minimum = l.empty() ? val : min(l.top().first, val);
        l.push({ minimum, val });
    }

    void pop()
    {
        l.pop();
    }

    int top()
    {
        return l.top().second;
    }

    int getMin()
    {
        return l.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
