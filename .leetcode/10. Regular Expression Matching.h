class Solution
{
    struct Token
    {
        char c;
        bool repeat;
        Token(char c, bool repeat) : c(c), repeat(repeat) {};
    };

    static vector <Token> parse(const string &regular)
    {
        vector <Token> Tokens;
        {
            size_t i = 0;
            Tokens.reserve(regular.size());
            while (i != regular.size())
            {
                char c = regular[i];
                ++i;
                bool repeat = i != regular.size() && regular[i] == '*';
                if (repeat) { ++i; }
                Tokens.emplace_back(c, repeat);
            }
        }

        if (!Tokens.empty())
        {
            auto it = next(Tokens.begin());
            while (it != Tokens.end())
            {
                if (it->repeat && prev(it)->repeat)
                {
                    if (prev(it)->c == '.' ||
                        prev(it)->c == it->c)
                    {
                        it = Tokens.erase(it);
                    }
                    else if (it->c == '.')
                    {
                        Tokens.erase(prev(it));
                    }
                    else
                    {
                        ++it;
                    }
                }
                else
                {
                    ++it;
                }
            }
        }
        Tokens.shrink_to_fit();
        return Tokens;
    }

    bool isMatch(string::const_iterator first,
                 string::const_iterator last,
                 vector<Token>::const_iterator TokensFirst,
                 vector<Token>::const_iterator TokensLast)
    {
        if (TokensFirst == TokensLast) { return first == last; }

        bool match = first != last &&
                     (TokensFirst->c == '.' ||
                      TokensFirst->c == *first);

        if (!match)
        {
            return TokensFirst->repeat &&
                   isMatch(first, last,
                           next(TokensFirst),
                           TokensLast);
        }

        if (!TokensFirst->repeat)
        {
            return isMatch(next(first), last,
                           next(TokensFirst),
                           TokensLast);
        }

        return isMatch(next(first), last,
                       TokensFirst,
                       TokensLast)
               ||
               isMatch(next(first), last,
                       next(TokensFirst),
                       TokensLast)
               || isMatch(first, last,
                          next(TokensFirst),
                          TokensLast);
    }

public:
    bool isMatch(string s, string p)
    {
        auto tokens = parse(p);
        return isMatch(s.cbegin(), s.cend(),
                       tokens.cbegin(), tokens.cend());
    }
};
