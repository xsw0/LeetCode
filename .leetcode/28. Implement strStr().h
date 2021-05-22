class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        for (size_t i = 0; i + needle.size() <= haystack.size(); i++)
        {
            size_t j = 0;
            for (; j < needle.size() && haystack[i + j] == needle[j]; j++)
            {
            }
            if (j == needle.size())
            {
                return i;
            }
        }
        return -1;
    }
};
