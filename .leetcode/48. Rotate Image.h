class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        reverse(matrix.begin(), matrix.end());
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            assert(matrix.size() == matrix[i].size());
            for (size_t j = i + 1; j < matrix.size(); ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
