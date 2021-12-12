class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> result = {{}};
        size_t size = 1;
        for (auto n: nums)
        {
            for (size_t i = 0; i < size; i++)
            {
                result.push_back(result[i]);
                result.back().push_back(n);
            }
            size *= 2;
        }
        return result;
    }
};
