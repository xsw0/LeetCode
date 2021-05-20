class Solution
{
 public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        st.push(-1);
        int longest = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (st.top() != -1 && s[st.top()] == '(' && s[i] == ')')
            {
                st.pop();
                int len = i - st.top();
                if (len > longest) longest = len;
            }
            else
            {
                st.push(i);
            }
        }
        return longest;
    }
};
