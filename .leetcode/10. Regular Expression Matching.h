class Solution
{
    static bool match(
        const char* sFirst, const char* sLast,
        const char* pFirst, const char* pLast)
    {
        if (sFirst == sLast && pFirst == pLast) return true;

        if (pFirst == pLast) return false;

        --pLast;

        if (sFirst == sLast)
        {
            if (*pLast != '*') return false;
            return match(sFirst, sLast, pFirst, pLast - 1);
        }

        --sLast;

        if (*pLast == '.' || *sLast == *pLast)
        {
            return match(sFirst, sLast, pFirst, pLast);
        }

        if (*pLast != '*') return false;

        --pLast;

        if (*pLast == '.' || *sLast == *pLast)
        {
            if (match(sFirst, sLast, pFirst, pLast + 2)) return true;
        }
        return match(sFirst, sLast + 1, pFirst, pLast);
    }

public:
    bool isMatch(string s, string p)
    {
        return match(
            s.c_str(), s.c_str() + s.size(),
            p.c_str(), p.c_str() + p.size()
        );
    }
};
