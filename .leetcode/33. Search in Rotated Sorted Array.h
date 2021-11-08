class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        if (nums.empty()) return -1;

        auto offset = [](const vector<int>& nums)
        {
            size_t l = 0;
            size_t r = nums.size();
            while (l != r)
            {
                auto mid = l + (r - l) / 2;
                if (nums[l] < nums[mid])
                {
                    l = mid;
                }
                else
                {
                    r = mid;
                }
            }
            return (l + 1) % nums.size();
        }(nums);

        size_t l = 0;
        size_t r = nums.size();
        while (l != r)
        {
            auto mid = l + (r - l) / 2;
            auto value = nums[(mid + offset) % nums.size()];
            if (target < value)
            {
                r = mid;
            }
            else if (target > value)
            {
                l = mid + 1;
            }
            else
            {
                return static_cast<int>((mid + offset) % nums.size());
            }
        }
        return -1;
    }
};
