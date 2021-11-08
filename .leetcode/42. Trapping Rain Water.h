class Solution
{
public:
    int trap(vector<int>& height)
    {
        auto l = height.cbegin();
        auto r = height.cend();
        int lMax = 0;
        int rMax = 0;
        int count = 0;
        while (l != r)
        {
            if (lMax < rMax)
            {
                if (*l > lMax)
                {
                    lMax = *l;
                }
                else
                {
                    count += lMax - *l;
                }
                ++l;
            }
            else
            {
                --r;
                if (*r > rMax)
                {
                    rMax = *r;
                }
                else
                {
                    count += rMax - *r;
                }
            }
        }
        return count;
    }
};
