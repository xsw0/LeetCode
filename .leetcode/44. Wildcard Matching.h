class Solution
{
public:
    bool isMatch(string s, string p)
    {
        size_t i = 0;
        size_t j = 0;
        size_t star = p.size();
        size_t start = s.size();
        while (s[i])
        {
            if ((p[j] == '?') || (p[j] == s[i]))
            {
                ++i, ++j;
            }
            else if (p[j] == '*')
            {
                star = j;
                start = i;
                ++j;
            }
            else if (p[star] == '*')
            {
                ++start;
                i = start;
                j = star + 1;
            }
            else
            {
                return false;
            }
        }
        while (p[j] == '*') { ++j; }
        return j == p.size();
    }
};
