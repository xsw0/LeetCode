class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;

        function<void(int, int)> helper;

        vector<int> comb;
        helper = [&](int n, int k)
        {
            if (k == 0)
            {
                result.push_back(comb);
            }
            else if (k <= n)
            {
                while (n > 0)
                {
                    comb.push_back(n);
                    helper(n - 1, k - 1);
                    comb.pop_back();
                    --n;
                }
            }
        };

        helper(n, k);

        return result;
    }
};
