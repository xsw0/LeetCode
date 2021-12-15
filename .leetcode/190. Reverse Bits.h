class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
//        bitset<32> bs{ n };
//        for (size_t i = 0; i != 32 / 2; ++i)
//        {
//            bool bit = bs[i];
//            bs[i] = bs[31 - i];
//            bs[31 - i] = bit;
//        }
//        return bs.to_ulong();

        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
