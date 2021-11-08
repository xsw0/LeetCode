class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int n = 1;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it)
        {
            auto temp = n + *it;
            *it = temp % 10;
            n = temp / 10;
        }
        if (n != 0)
        {
            digits.insert(digits.begin(), n);
        }
        return digits;
    }
};
