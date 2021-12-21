class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int maximum = 0;
        int count = 0;
        int val = numeric_limits<int>::min();
        for (auto&& i: nums)
        {
            if (i == val + 1)
            {
                ++count;
                ++val;
            }
            else if (i != val)
            {
                if (count > maximum) { maximum = count; }
                count = 1;
                val = i;
            }
        }
        if (count > maximum) { maximum = count; }
        return maximum;
    }
};
