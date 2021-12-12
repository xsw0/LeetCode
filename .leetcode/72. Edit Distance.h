class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        const string& shorter = word1.size() <= word2.size() ? word1 : word2;
        const string& longer = word1.size() > word2.size() ? word1 : word2;

        if (shorter.empty()) return longer.size();

        vector<size_t> dp;
        dp.reserve(shorter.size());
        for (size_t i = 1; i <= shorter.size(); ++i) dp.emplace_back(i);
        for (size_t i = 0; i < longer.size(); ++i)
        {
            size_t up = i;
            size_t left = i + 1;
            for (size_t j = 0; j < shorter.size(); ++j)
            {
                size_t temp = dp[j];
                if (longer[i] == shorter[j]) dp[j] = up;
                else dp[j] = 1 + min(up, min(left, dp[j]));
                left = dp[j];
                up = temp;
            }
        }
        return dp.back();
    }
};
