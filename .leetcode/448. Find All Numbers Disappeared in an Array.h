class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        for (int i = 0; i != nums.size(); ++i)
        {
            while (i != nums[i] - 1 && nums[nums[i] - 1] - 1 != nums[i] - 1)
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> disappear;
        disappear.reserve(nums.size());
        for (int i = 0; i != nums.size(); ++i)
        {
            if (i + 1 != nums[i])
            {
                disappear.emplace_back(i + 1);
            }
        }
        return disappear;
    }
};
