class Solution
{
public:
    int mySqrt(int x)
    {
        int lower = 0;
        constexpr static int ROUND_DOWN_SQRT_OF_MAX_INT = 46340;
        int upper = min(x, ROUND_DOWN_SQRT_OF_MAX_INT);
        while (lower != upper)
        {
            auto avg = (lower + upper + 1) / 2;
            auto square = avg * avg;
            if (square == x)
            {
                return avg;
            }
            else if (square < x)
            {
                lower = avg;
            }
            else
            {
                upper = avg - 1;
            }
        }
        return lower;
    }
};
