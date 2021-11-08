class Solution
{
public:
    bool isValid(string s)
    {
        stack<char, list<char>> st;
        for (const char c: s)
        {
            switch (c)
            {
            case '{':
                st.push('}');
                break;
            case '[':
                st.push(']');
                break;
            case '(':
                st.push(')');
                break;
            default:
                if (st.empty() || st.top() != c) return false;
                st.pop();
                break;
            }
        }
        return st.empty();
    }
};
