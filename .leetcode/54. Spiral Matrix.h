class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        size_t height = matrix.size();
        size_t width = matrix.front().size();

        vector<int> result;
        result.reserve(height * width);

        size_t lastRow = height;
        size_t lastCol = width;

        size_t offset = 0;
        size_t offsetBound = min(height, width) / 2;
        for (; offset < offsetBound; ++offset)
        {
            --lastRow;
            --lastCol;
            for (size_t col = offset; col < lastCol; ++col) result.push_back(matrix[offset][col]);
            for (size_t row = offset; row < lastRow; ++row) result.push_back(matrix[row][lastCol]);
            for (size_t col = lastCol; col > offset; --col) result.push_back(matrix[lastRow][col]);
            for (size_t row = lastRow; row > offset; --row) result.push_back(matrix[row][offset]);
        }
        if (min(height, width) % 2 != 0)
        {
            if (height < width)
            {
                for (size_t col = offset; col < lastCol; ++col) result.push_back(matrix[offset][col]);
            }
            else
            {
                for (size_t row = offset; row < lastRow; ++row) result.push_back(matrix[row][offset]);
            }
        }
        return result;
    }
};
