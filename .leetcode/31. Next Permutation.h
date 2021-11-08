class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        if (nums.size() != 0)
        {
            auto p0 = nums.rbegin();
            auto p1 = next(p0);
            while (p1 != nums.rend() && *p1 >= *p0)
            {
                ++p1;
                ++p0;
            }
            if (p1 == nums.rend())
            {
                reverse(nums.begin(), nums.end());
            }
            else
            {
                p0 = upper_bound(nums.rbegin(), p0, *p1);
                swap(*p0, *p1);
                reverse(nums.rbegin(), p1);
            }
        }
    }
};
