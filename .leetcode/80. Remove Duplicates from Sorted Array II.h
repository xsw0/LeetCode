class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        auto it = nums.begin();
        auto first = nums.cbegin();
        while (first != nums.cend())
        {
            auto last = find_if_not(first, nums.cend(), [&](int n) { return n == *first; });

            if (it != first) { *it = *first; }
            ++it;
            ++first;

            if (first != last)
            {
                if (it != first) { *it = *first; }
                ++it;
                first = last;
            }
        }
        return distance(nums.begin(), it);
    }
};
