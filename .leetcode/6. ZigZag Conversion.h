class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || s.size() <= numRows) { return s; }
        string ZigZag;
        ZigZag.reserve(s.size());
        if (numRows == 2)
        {
            for (int i = 0; i < s.size(); i += 2)
            {
                ZigZag.push_back(s[i]);
            }
            for (int i = 1; i < s.size(); i += 2)
            {
                ZigZag.push_back(s[i]);
            }
            return ZigZag;
        }
        else
        {
            for (int i = 0; i < s.size(); i += (numRows - 1) * 2)
            {
                ZigZag.push_back(s[i]);
            }
            for (int i = 1; i < numRows - 1; ++i)
            {
                ZigZag.push_back(s[i]);
                int j = (numRows - 1) * 2;
                while (true)
                {
                    if (j - i >= s.size()) { break; }
                    ZigZag.push_back(s[j - i]);

                    if (j + i >= s.size()) { break; }
                    ZigZag.push_back(s[j + i]);

                    j += (numRows - 1) * 2;
                }
            }
            for (int i = numRows - 1; i < s.size(); i += (numRows - 1) * 2)
            {
                ZigZag.push_back(s[i]);
            }
            return ZigZag;
        }
    }
};
