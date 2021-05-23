class Solution
{
public:
    int mySqrt(int x)
    {
        int minR = 0;
        int max = min(x, 46340);
        auto square = [](const int i) {
            return i * i;
        };
        while (minR < max)
        {
            if (auto avg = (minR + max + 1) / 2, i = square(avg); i == x)
            {
                return avg;
            }
            else if (i < x)
            {
                minR = avg;
            }
            else
            {
                max = avg - 1;
            }
        }
        return max;
    }
};
