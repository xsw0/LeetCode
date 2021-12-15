class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        if (nums.empty()) { return false; }
        std::sort(nums.begin(), nums.end());

        for (auto it = next(nums.cbegin()); it != nums.cend(); ++it)
        {
            if (*it == *prev(it)) { return true; }
        }
        return false;
    }
};
