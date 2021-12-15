class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
//        return static_cast<int>(bitset<32>{ n }.count());
        int count = 0;
        while (n)
        {
            n &= n - 1;
            ++count;
        }
        return count;
    }
};
