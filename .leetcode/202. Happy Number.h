class Solution
{
public:
    bool isHappy(int n)
    {
        auto sum_of_squares = [](int n)
        {
            int count = 0;
            while (n)
            {
                auto x = n % 10;
                count += x * x;
                n /= 10;
            }
            return count;
        };

        static constexpr auto table = [&]
        {
            constexpr size_t maximum = 730; // 1999999999 => 9 * 9^2 + 1 * 1^2 = 730
            array<int, maximum + 1> table{};
            for (int i = 0; i != table.size(); ++i)
            {
                table[i] = sum_of_squares(i);
            }
            bool b = true;
            while (b)
            {
                b = false;
                for (auto& n: table)
                {
                    if (n != 1 && table[n] == 1)
                    {
                        n = 1;
                        b = true;
                    }
                }
            }
            return table;
        }();

        return table[sum_of_squares(n)] == 1;
    }
};
