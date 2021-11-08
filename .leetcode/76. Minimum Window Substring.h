class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.size() > s.size()) return "";
        array<int, 'z' - 'A' + 1> count{};
        for (auto c: t) --count[c - 'A'];

        int match = t.size();

        auto l = s.cbegin();
        auto r = s.cbegin();
        while (r != s.cend() && match > 0)
        {
            ++count[*r - 'A'];
            if (count[*r - 'A'] <= 0) --match;
            ++r;
        }
        auto first = l;
        auto last = r;
        if (match > 0) return "";
        while (r != s.cend())
        {
            if (count[*l - 'A'] > 0)
            {
                --count[*l - 'A'];
                ++l;
                if (r - l < last - first) first = l, last = r;
            }
            else
            {
                ++count[*r - 'A'];
                ++r;
            }
        }
        while (count[*l - 'A'] > 0)
        {
            --count[*l - 'A'];
            ++l;
            if (r - l < last - first) first = l, last = r;
        }
        return s.substr(first - s.cbegin(), last - first);
    }
};
