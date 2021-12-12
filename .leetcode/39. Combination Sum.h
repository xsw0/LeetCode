class Solution
{
    vector<vector<int>> result;
    vector<int> cache;
    vector<int>::const_reverse_iterator end;
    void helper(vector<int>::const_reverse_iterator it, int target)
    {
        if (target == 0)
        {
            result.push_back(cache);
        }
        else if (it != end)
        {
            if (*it <= target)
            {
                cache.push_back(*it);
                helper(it, target - *it);
                cache.pop_back();
            }
            helper(next(it), target);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        end = candidates.crend();
        helper(candidates.crbegin(), target);
        return result;
    }
};
