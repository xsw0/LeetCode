class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> result;
        result.reserve(1 << n);
        bitset<16> mask;
        bitset<16> gray;
        result.push_back(static_cast<int>(gray.to_ulong()));
        while (true)
        {
            for (size_t i = 0; i < n; ++i)
            {
                if (!mask[i])
                {
                    gray.flip(i);
                    mask.set(i);
                    result.push_back(static_cast<int>(gray.to_ulong()));
                    goto end;
                }
                else
                {
                    mask.reset(i);
                }
            }
            break;
        end:;
        }
        return result;
    }
};
