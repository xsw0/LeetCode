class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        if (nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        result.reserve(nums.size());
        for (auto it = nums.cbegin(); it != nums.cend(); ++it)
        {
            if (it != nums.cbegin() && *it == *prev(it)) continue;
            int n = -*it;
            auto l = next(it);
            auto r = prev(nums.cend());
            while (l < r)
            {
                if (*l + *r == n)
                {
                    result.push_back({ *it, *l, *r });
                    do
                    {
                        ++l, --r;
                    } while (l < r && *l == *prev(l) && *r == *next(r));
                }
                else if (*l + *r < n) { ++l; }
                else { --r; }
            }
        }
        return result;
    }
};
