class Solution
{
public:
    bool isNumber(string s)
    {
        auto current = s.cbegin();
        auto digits = [&]()
        {
            if (*current >= '0' && *current <= '9')
            {
                do ++current; while (*current >= '0' && *current <= '9');
                return true;
            }
            else
            {
                return false;
            }
        };
        auto integer = [&]()
        {
            auto start = current;
            if (*current == '+' || *current == '-') ++current;
            if (digits())
            {
                return true;
            }
            else
            {
                current = start;
                return false;
            }
        };
        auto decimal = [&]()
        {
            auto start = current;
            if (*current == '+' || *current == '-') ++current;
            if (digits())
            {
                if (*current == '.')
                {
                    ++current;
                    digits();
                }
                return true;
            }
            else
            {
                if (*current != '.')
                {
                    current = start;
                    return false;
                }
                ++current;
                if (digits()) return true;
                current = start;
                return false;
            }
        };
        auto valid = [&]()
        {
            auto start = current;
            if (!decimal()) return false;
            if (*current == 'e' || *current == 'E')
            {
                ++current;
                if (integer()) return true;
                current = start;
                return false;
            }
            return true;
        };
        return valid() && current == s.cend();
    }
};
