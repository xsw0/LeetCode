class Solution
{
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        size_t rows = matrix.size();
        if (rows == 0) return 0;
        size_t cols = matrix.front().size();
        if (cols == 0) return 0;

        size_t maximum = 0;

        vector<size_t> left(cols, 0);
        vector<size_t> right(cols, cols);
        vector<size_t> height(cols, 0);
        for (size_t row = 0; row != rows; ++row)
        {
            {
                size_t index = 0;
                for (size_t col = 0; col != cols; ++col)
                {
                    if (matrix[row][col] == '0') { index = col + 1; }
                    else { left[col] = max(left[col], index); }
                }
            }
            {
                size_t index = cols;
                for (size_t col = cols; col != 0; --col)
                {
                    if (matrix[row][col - 1] == '0') { index = col - 1; }
                    else { right[col - 1] = min(right[col - 1], index); }
                }
            }
            for (size_t col = 0; col != cols; ++col)
            {
                if (matrix[row][col] == '0')
                {
                    height[col] = 0;
                    left[col] = 0;
                    right[col] = cols;
                }
                else
                {
                    ++height[col];
                    maximum = max(maximum, height[col] * (right[col] - left[col]));
                }
            }
        }

        return static_cast<int>(maximum);
    }
};
