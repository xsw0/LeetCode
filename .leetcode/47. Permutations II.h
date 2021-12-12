class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result{ nums };
        while (next_permutation(nums.begin(), nums.end()))
        {
            result.push_back(nums);
        }
        return result;
    }
};
