class Solution
{
public:
    string getPermutation(int n, int k)
    {
        constexpr static array<int, 10> fact{ 0, 1, 1, 2, 6, 24, 120, 720, 5040, 40320, };
        constexpr static array<const string_view, 10> sss{
            "",
            "1",
            "12",
            "123",
            "1234",
            "12345",
            "123456",
            "1234567",
            "12345678",
            "123456789"
        };

        string s{ sss[n] };
        --k;
        for (size_t i = 0; i < s.size(); ++i)
        {
            for (size_t j = i + 1; j <= i + k / fact[n - i]; ++j)
            {
                swap(s[i], s[j]);
            }
            k %= fact[n - i];
        }

        return s;
    }
};
