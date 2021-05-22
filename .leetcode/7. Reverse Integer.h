class Solution
{
public:
    int reverse(int x)
    {
        int result = 0;
        while (x != 0)
        {
            if (result < std::numeric_limits<int>::min() / 10 ||
                result > std::numeric_limits<int>::max() / 10)
            {
                return 0;
            }
            result *= 10;
            if (x < 0 && result < std::numeric_limits<int>::min() - x % 10 ||
                x > 0 && result > std::numeric_limits<int>::max() - x % 10)
            {
                return 0;
            }
            result += x % 10;
            x /= 10;
        }
        return result;
    };
};
