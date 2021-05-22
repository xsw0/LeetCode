class Solution
{
    int64_t combination(int64_t n, int64_t k)
    {
        int64_t result = 1;
        for (int64_t i = n - k + 1, j = 1; i <= n; ++i, ++j)
        {
            result *= i;
            assert(result % j == 0);
            result /= j;
        }
        return result;
    }
public:
    int uniquePaths(int m, int n)
    {
        return static_cast<int>(combination(m + n - 2, max(m, n) - 1));
    }
};
