class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int sum = 0;
        int max = numeric_limits<int>::min();
        for (auto n: nums)
        {
            sum += n;
            max = std::max(max, sum);
            sum = std::max(0, sum);
        }
        return max;
    }
};
