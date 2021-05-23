class Solution
{
public:
    int romanToInt(string s)
    {
        static const unordered_map<char, int> table = {
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 }
        };

        int Integer = table.at(s.back());

        for (size_t i = 1; i < s.size(); ++i)
        {
            if (table.at(s[i - 1]) < table.at(s[i]))
            {
                Integer -= table.at(s[i - 1]);
            }
            else
            {
                Integer += table.at(s[i - 1]);
            }
        }

        return Integer;
    }
};
