class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int max = INT_MIN;
        for (auto e : nums)
        {
            sum += e;
            max = std::max(max, sum);
            sum = std::max(0, sum);
        }
        return max;
    }
};
