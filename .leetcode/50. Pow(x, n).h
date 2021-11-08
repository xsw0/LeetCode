class Solution
{
    double positivePower(double x, int n)
    {
        assert(n > 0);
        if (n == 1) return x;
        if (n % 2 == 0)
        {
            return positivePower(x * x, n / 2);
        }
        else
        {
            return x * positivePower(x * x, n / 2);
        }
    }
public:
    double myPow(double x, int n)
    {
        switch (n)
        {
        case 0:
            return 1.0;
        case 1:
            return x;
        case -1:
            return 1.0 / x;
        case std::numeric_limits<int>::min():
            return (1.0 / x) * positivePower(1.0 / x, std::numeric_limits<int>::max());
        default:
            if (n < 0)
            {
                assert(x != 0.0);
                n = -n;
                x = 1.0 / x;
            }
            return positivePower(x, n);
        }
    }
};
