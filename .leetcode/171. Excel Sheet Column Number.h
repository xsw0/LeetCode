class Solution
{
public:
    int titleToNumber(string s)
    {
        int result = 0;
        int n = 1;
        for (auto it = s.crbegin(); it != s.crend(); ++it)
        {
            result += (*it - ('A' - 1)) * n;
            if (n < INT_MAX / 26)
            {
                n *= 26;
            }
        }
        return result;
    }
};
