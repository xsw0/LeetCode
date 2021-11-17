class Solution
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        auto* left = new size_t[heights.size()];
        auto* right = new size_t[heights.size()];

        for (size_t i = 0; i != heights.size(); ++i)
        {
            size_t bound = i;
            while (bound != 0 && heights[bound - 1] >= heights[i]) bound = left[bound - 1];
            left[i] = bound;
        }

        for (size_t i = heights.size(); i != 0; --i)
        {
            size_t bound = i;
            while (bound != heights.size() && heights[bound] >= heights[i - 1]) bound = right[bound];
            right[i - 1] = bound;
        }

        size_t maximum = 0;
        for (size_t i = 0; i != heights.size(); ++i)
        {
            maximum = max(maximum, heights[i] * (right[i] - left[i]));
        }

        delete[] left;
        delete[] right;

        return static_cast<int>(maximum);
    }
};
