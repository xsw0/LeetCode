class Solution
{
public:
    string multiply(string num1, string num2)
    {
        string product(num1.size() + num2.size(), '0');
        function<void(size_t, int)> carry =
            [&](size_t index, int value)
            {
                int sum = product[index] - '0' + value;
                product[index] = '0' + sum % 10;
                if (sum >= 10)
                {
                    carry(index + 1, sum / 10);
                }
            };
        for (size_t i = 0; i < num1.size(); ++i)
        {
            if (num1[i] != '0')
            {
                for (size_t j = 0; j < num2.size(); ++j)
                {
                    carry(num1.size() - i - 1 + num2.size() - j - 1, (num1[i] - '0') * (num2[j] - '0'));
                }
            }
        }

        auto it = product.rbegin();
        while (it != product.rend() && *it == '0')
        {
            ++it;
        }

        return it == product.rend() ? "0" : string{ it, product.rend() };
    }
};
