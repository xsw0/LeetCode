class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        return reduce(nums.cbegin(), nums.cend(), 0, bit_xor<>());
    }
};
