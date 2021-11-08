class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        auto l = nums.cbegin();
        auto r = nums.cend();
        vector<int>::const_iterator mid;
        while (l != r)
        {
            mid = l + distance(l, r) / 2;
            if (target < *mid)
            {
                r = mid;
            }
            else if (target > *mid)
            {
                l = next(mid);
            }
            else
            {
                return {
                    static_cast<int>(
                        distance(nums.cbegin(), lower_bound(l, mid, target))
                    ),
                    static_cast<int>(
                        distance(nums.cbegin(), upper_bound(mid, r, target))
                    ) - 1
                };
            }
        }
        return { -1, -1 };
    }
};
