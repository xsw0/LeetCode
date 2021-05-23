int climbStairs(int n)
{
    if (n < 4)
    {
        return n;
    }
    else if (n % 2 == 0)
    {
        int t1 = climbStairs(n / 2);
        int t2 = climbStairs(n / 2 - 1);
        return t1 * t1 + t2 * t2;
    }
    else
    {
        int t1 = climbStairs(n / 2);
        int t2 = climbStairs(n / 2 - 1);
        int t3 = climbStairs(n / 2 + 1);
        return t1 * (t2 + t3);
    }
}
