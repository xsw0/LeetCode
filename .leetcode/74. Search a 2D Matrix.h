class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        size_t l = 0;
        size_t r = matrix.size() * matrix.front().size();
        while (l != r)
        {
            auto mid = l + (r - l - 1) / 2;
            auto value = matrix[mid / matrix.front().size()][mid % matrix.front().size()];
            if (value > target)
            {
                r = mid;
            }
            else if (value < target)
            {
                l = mid + 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
