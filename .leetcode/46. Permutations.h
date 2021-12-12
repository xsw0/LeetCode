class Solution
{
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        constexpr static array<size_t, 21> size = []
        {
            array<size_t, 21> result = { 1 };
            for (size_t i = 1; i < result.size(); ++i)
            {
                result[i] = i * result[i - 1];
            }
            return result;
        }();
        vector<vector<int>> result;
        result.reserve(size[nums.size()]);
        result.push_back(nums);
        for (size_t i = 1; i < size[nums.size()]; i++)
        {
            next_permutation(nums.begin(), nums.end());
            result.push_back(nums);
        }
        return result;
    }
};
