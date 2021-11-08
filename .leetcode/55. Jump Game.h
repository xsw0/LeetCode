class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int i = 0;
        int bound = 1;
        while (i < bound && bound < nums.size())
        {
            if (i + nums[i] >= bound) bound = i + nums[i] + 1;
            ++i;
        }
        return bound >= nums.size();
    }
};
