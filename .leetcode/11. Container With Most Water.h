class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int max = 0;
        size_t i = 0;
        size_t j = height.size() - 1;
        while (i < j)
        {
            max = std::max(max, static_cast<int>((j - i) * std::min(height[i], height[j])));
            if (height[i] < height[j])
            {
                ++i;
            }
            else if (height[i] > height[j])
            {
                --j;
            }
            else
            {
                ++i;
                --j;
            }
        }
        return max;
    }
};
