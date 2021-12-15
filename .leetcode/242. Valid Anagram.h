class Solution
{
public:
    bool isAnagram(string s, string t)
    {
//        std::sort(s.begin(), s.end());
//        std::sort(t.begin(), t.end());
//        return s == t;
        array<int, 26> count{};
        for (auto&& c: s) { ++count[c - 'a']; }
        for (auto&& c: t) { --count[c - 'a']; }
        for (auto&& i: count) { if (i != 0) { return false; }}
        return true;
    }
};
