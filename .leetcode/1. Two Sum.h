class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, size_t> um;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (um.find(nums[i]) != um.end())
            {
                return { static_cast<int>(um[nums[i]]), static_cast<int>(i) };
            }
            else
            {
                um[target - nums[i]] = i;
            }
        }
        return { -1, -1 };
    }
};
