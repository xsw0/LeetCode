class Solution
{
public:
    int myAtoi(string s)
    {
        size_t i = 0;
        while (i < s.size() && s[i] == ' ') ++i;

        int sign = -1;
        if (i < s.size())
        {
            switch (s[i])
            {
            case '-':
                sign = 1;
            case '+':
                ++i;
            }
        }

        int n = 0;
        while (i < s.size() && s[i] >= '0' && s[i] <= '9')
        {
            if (n < std::numeric_limits<int>::min() / 10)
            {
                return sign < 0 ? numeric_limits<int>::max() : numeric_limits<int>::min();
            }
            n *= 10;
            if (n < std::numeric_limits<int>::min() + (s[i] - '0'))
            {
                return sign < 0 ? numeric_limits<int>::max() : numeric_limits<int>::min();
            }
            n -= s[i] - '0';
            ++i;
        }
        if (sign < 0 && n == numeric_limits<int>::min())
        {
            return numeric_limits<int>::max();
        }
        return sign * n;
    }
};
