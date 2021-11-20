class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int maximum = 0;
        int minimum = numeric_limits<int>::max();
        for (auto i: prices)
        {
            int profit = i - minimum;
            if (profit > maximum) { maximum = profit; }
            if (i < minimum) { minimum = i; }
        }
        return maximum;
    }
};
