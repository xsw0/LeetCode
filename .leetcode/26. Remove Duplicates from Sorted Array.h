class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        auto it0 = nums.begin();
        size_t result = 1;
        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            if (*it > *it0)
            {
                ++it0;
                *it0 = *it;
                ++result;
            }
        }
        return result;
    }
};
