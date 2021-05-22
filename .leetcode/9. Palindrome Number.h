class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0) { return false; }
        if (x < 10) { return true; }
        if (x % 10 == 0) { return false; }
        int64_t n = 0;
        int64_t m = x;
        while (m != 0)
        {
            n *= 10;
            n += m % 10;
            m /= 10;
        }
        return n == x;
    }
};
