class Solution
{
    static pair <string::const_iterator,
    string::const_iterator>
    longestPalindrome(string::const_iterator first,
                      string::const_iterator last)
    {
        size_t size = distance(first, last);
        auto l = first + size / 2 - 1;
        auto r = first + (size + 1) / 2;
        while (r != last)
        {
            if (*l != *r)
            {
                return { next(l), r };
            }
            --l, ++r;
        }
        return { first, last };
    }

public:
    string longestPalindrome(string s)
    {
        if (s.size() < 2) { return s; }
        auto maximum = longestPalindrome(s.cbegin(), s.cend());

        size_t i = 1;
        while (true)
        {
            if (distance(maximum.first, maximum.second) + i >= s.size()) { break; }

            pair <string::const_iterator, string::const_iterator> p;

            p = longestPalindrome(s.cbegin() + i, s.cend());
            if (distance(p.first, p.second) >
                distance(maximum.first, maximum.second))
            {
                maximum = p;
            }

            if (distance(maximum.first, maximum.second) + i >= s.size()) { break; }

            p = longestPalindrome(s.cbegin(), s.cend() - i);
            if (distance(p.first, p.second) >
                distance(maximum.first, maximum.second))
            {
                maximum = p;
            }

            ++i;
        }
        return s.substr(distance(s.cbegin(), maximum.first), distance(maximum.first, maximum.second));
    }
};
