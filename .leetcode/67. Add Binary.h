class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result;
        auto n = 0;
        auto ita = a.crbegin(), itb = b.crbegin();
        while (true)
        {
            if (ita == a.crend())
            {
                while (itb != b.crend())
                {
                    if (isdigit(*itb))
                    {
                        unsigned temp = *itb - '0' + n;
                        n = temp / 2;
                        result.push_back(temp % 2 + '0');
                    }
                    ++itb;
                }
                break;
            }
            if (itb == b.crend())
            {
                while (ita != a.crend())
                {
                    if (isdigit(*ita))
                    {
                        unsigned temp = *ita - '0' + n;
                        n = temp / 2;
                        result.push_back(temp % 2 + '0');
                    }
                    ++ita;
                }
                break;
            }
            if (isdigit(*ita) && isdigit(*itb))
            {
                unsigned temp = (*ita - '0') + (*itb - '0') + n;
                n = temp / 2;
                result.push_back(temp % 2 + '0');
                ++ita, ++itb;
            }
            else
            {
                if (!isdigit(*ita))
                {
                    ++ita;
                }
                if (!isdigit(*itb))
                {
                    ++itb;
                }
            }
        }
        if (n != 0)
        {
            result.push_back(n + '0');
        }
        if (result.empty())
        {
            return "0";
        }
        else
        {
            reverse(result.begin(), result.end());
        }
        return result;
    }
};
