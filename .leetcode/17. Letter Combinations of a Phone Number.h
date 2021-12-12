class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty()) return {};
        static const array<vector<char>, 8> table = {
            vector<char>{ 'a', 'b', 'c' },
            vector<char>{ 'd', 'e', 'f' },
            vector<char>{ 'g', 'h', 'i' },
            vector<char>{ 'j', 'k', 'l' },
            vector<char>{ 'm', 'n', 'o' },
            vector<char>{ 'p', 'q', 'r', 's' },
            vector<char>{ 't', 'u', 'v' },
            vector<char>{ 'w', 'x', 'y', 'z' }
        };
        vector<size_t> index;
        index.reserve(digits.size());
        for (const char c: digits)
        {
            index.push_back(c - '2');
        }
        vector<size_t> count(digits.size(), 0);
        vector<string> result;
        result.reserve(256);
        bool carry = false;
        while (!carry)
        {
            result.push_back("");
            result.back().reserve(digits.size());
            for (int i = 0; i < count.size(); ++i)
            {
                result.back().push_back(table[index[i]][count[i]]);
            }
            carry = true;
            for (size_t i = 0; carry && i < index.size(); ++i)
            {
                ++count[i];
                if (count[i] == table[index[i]].size())
                {
                    count[i] = 0;
                    carry = true;
                }
                else
                {
                    carry = false;
                }
            }
        }
        result.shrink_to_fit();
        return result;
    }
};
