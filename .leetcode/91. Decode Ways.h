class Solution
{
    map<string::const_iterator, int> m;
    int numDecodings(
        string::const_iterator first,
        string::const_iterator last
    )
    {
        if (first == last) return 1;
        if (*first == '0') return 0;
        auto it = m.find(first);
        if (it == m.end())
        {
            if (next(first) == last || *first > '2' || *first == '2' && *next(first) > '6')
            {
                it = m.insert({ first, numDecodings(next(first), last) }).first;
            }
            else
            {
                it = m.insert({
                                  first,
                                  numDecodings(next(first), last) +
                                  numDecodings(next(next(first)), last)
                              }).first;
            }
        }
        return it->second;
    }
public:
    int numDecodings(string s)
    {
        m.clear();
        return numDecodings(s.cbegin(), s.cend());
    }
};
