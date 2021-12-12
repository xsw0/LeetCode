class Solution
{
public:
    int longestValidParentheses(string& s)
    {
        size_t start = 0;
        size_t longest = 0;
        stack<size_t> st;
        for (size_t i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '(':
                st.push(i);
                break;
            case ')':
                if (st.empty())
                {
                    start = i + 1;
                }
                else
                {
                    st.pop();
                    auto length = st.empty() ? i - start + 1 : i - st.top();
                    longest = max(longest, length);
                }
                break;
            default:
                assert(0);
            }
        }
        return longest;
    }
};
