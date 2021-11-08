class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        int i = 0;
        while (i < nums.size() && i + 1 == nums[i])
        {
            ++i;
        }
        return i + 1;
    }
};
