class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        std::function<void(string, int, int)> f =
            [&](string s, int l, int r)
            {
                if (l == 0 && r == 0)
                {
                    result.push_back(s);
                }
                else
                {
                    if (l > 0) f(s + "(", l - 1, r);
                    if (l < r) f(s + ")", l, r - 1);
                }
            };
        f("", n, n);
        return result;
    }
};
