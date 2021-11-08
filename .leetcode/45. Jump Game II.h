class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int count = 0;
        int end = 0;
        int farthest = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (i + nums[i] > farthest) farthest = i + nums[i];
            if (i == end)
            {
                ++count;
                end = farthest;
            }
        }
        return count;
    }
};
