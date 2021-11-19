class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        array<int, 21> arr{};
        for (auto i: nums) ++arr[i + 10];
        vector<vector<int>> result{{}};
        result.reserve(1 << nums.size());
        for (int i = 0; i != arr.size(); ++i)
        {
            auto size = result.size();
            for (size_t j = 0; j < size; ++j)
            {
                for (size_t k = 1; k <= arr[i]; ++k)
                {
                    result.push_back(result[j]);
                    result.back().resize(result.back().size() + k, i - 10);
                }
            }
        }
        return result;
    }
};
