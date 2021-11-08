class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int closest = numeric_limits<int>::max();
        for (auto it = nums.cbegin(); it != nums.cend(); ++it)
        {
            int t = target - *it;
            auto l = next(it);
            auto r = prev(nums.cend());
            while (l < r)
            {
                int n = *l + *r;
                if (n > t)
                {
                    if (n - t < abs(closest)) closest = n - t;
                    --r;
                }
                else if (n < t)
                {
                    if (t - n < abs(closest)) closest = n - t;
                    ++l;
                }
                else
                {
                    return target;
                }
            }
        }
        return target + closest;
    }
};
