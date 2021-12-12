class Solution
{
    vector<vector<int>> result;
    vector<int> cache;
    map<int, int>::const_iterator end;
    void helper(map<int, int>::const_iterator it, int target)
    {
        if (target == 0)
        {
            result.push_back(cache);
        }
        else if (it != end)
        {
            helper(next(it), target);

            int bound = min(it->second, target / it->first);
            for (int i = 1; i <= bound; ++i)
            {
                cache.push_back(it->first);
                helper(next(it), target - i * it->first);
            }
            for (int i = 1; i <= bound; ++i)
            {
                cache.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        map<int, int, greater<>> m;
        for (auto n: candidates) ++m[n];
        end = m.cend();
        helper(m.cbegin(), target);
        return result;
    }
};
