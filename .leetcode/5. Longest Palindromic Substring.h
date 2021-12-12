class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty()) return s;

        auto extendL = [&](size_t index)
        {
            --index;
            auto l = index;
            while (l != 0 && s[l - 1] == s[index]) --l;
            return l;
        };

        auto extendR = [&](size_t index)
        {
            auto r = index + 1;
            while (s[r] == s[index]) ++r;
            return r;
        };

        auto extendBoth = [&](size_t l, size_t r) -> pair<size_t, size_t>
        {
            while (l != 0 && s[l - 1] == s[r]) --l, ++r;
            return { l, r };
        };

        auto size = [](size_t l, size_t r)
        {
            return r - l;
        };

        auto mid = s.size() / 2;
        auto l = extendL(mid + 1);
        auto r = extendR(mid);
        auto p = extendBoth(l, r);

        auto longestFirst = p.first;
        auto longestLast = p.second;
        while (size(longestFirst, longestLast) + 1 < size(0, l) * 2 ||
               size(longestFirst, longestLast) + 1 < size(r, s.size()) * 2)
        {
            if (size(0, l) > size(r, s.size()))
            {
                auto ll = extendL(l);
                auto p = extendBoth(ll, l);
                l = ll;
                if (size(p.first, p.second) > size(longestFirst, longestLast))
                {
                    longestFirst = p.first;
                    longestLast = p.second;
                }
            }
            else
            {
                auto rr = extendR(r);
                auto p = extendBoth(r, rr);
                r = rr;
                if (size(p.first, p.second) > size(longestFirst, longestLast))
                {
                    longestFirst = p.first;
                    longestLast = p.second;
                }
            }
        }
        return s.substr(longestFirst, size(longestFirst, longestLast));
    }
};
