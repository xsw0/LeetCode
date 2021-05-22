class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.empty()) return 0;
        auto highest = max_element(height.cbegin(), height.cend());

        int tot = 0;
        int bound;

        bound = 0;
        for (auto it = height.cbegin(); it != highest; ++it)
        {
            if (*it < bound)
            {
                tot += bound - *it;
            }
            else
            {
                bound = *it;
            }
        }

        bound = 0;
        for (auto it = prev(height.cend()); it != highest; --it)
        {
            if (*it < bound)
            {
                tot += bound - *it;
            }
            else
            {
                bound = *it;
            }
        }
        return tot;
    }
};
