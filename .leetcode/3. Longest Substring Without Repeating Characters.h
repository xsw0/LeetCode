class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        array<int, 127> index;
        index.fill(-1);
        int maximum = 0;
        int first = 0, last = 0;
        while (last != s.size())
        {
            if (index[s[last]] >= first)
            {
                maximum = std::max(maximum, last - first);
                first = index[s[last]] + 1;
            }
            index[s[last]] = last;
            ++last;
        }
        maximum = std::max(maximum, last - first);
        return maximum;
    }
};
