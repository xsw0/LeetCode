class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.empty()) return "";
        size_t size = numeric_limits<size_t>::max();
        for (const auto& s: strs)
        {
            size = std::min(size, s.size());
        }
        size_t i = 0;
        for (; i < size; ++i)
        {
            for (int j = 1; j < strs.size(); ++j)
            {
                if (strs[j][i] != strs.front()[i])
                {
                    return strs.front().substr(0, i);
                }
            }
        }
        return strs.front().substr(0, i);
    }
};
