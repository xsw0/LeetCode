class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int result = 0;
        auto it = s.crbegin();
        while (it != s.crend() && *it == ' ')
        {
            it++;
        }
        while (it != s.crend() && *it != ' ')
        {
            it++;
            result++;
        }
        return result;
    }
};
