class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        bool col0 = find_if(matrix.cbegin(), matrix.cend(),
                            [](const vector<int>& v)
                            {
                                return v.front() == 0;
                            }) != matrix.cend();
        if (find(matrix.front().cbegin(),
                 matrix.front().cend(),
                 0) != matrix.front().cend())
            matrix.front().front() = 0;
        for (size_t i = 1; i < matrix.size(); ++i)
        {
            assert(matrix[i].size() == matrix.front().size());
            for (size_t j = 1; j < matrix.front().size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix.front()[j] = 0;
                    matrix[i].front() = 0;
                }
            }
        }

        for (size_t i = 1; i < matrix.size(); ++i)
        {
            if (matrix[i].front() == 0)
                fill(matrix[i].begin(), matrix[i].end(), 0);
        }

        for (size_t col = 1; col < matrix.front().size(); ++col)
        {
            if (matrix.front()[col] == 0)
            {
                for (auto& row: matrix)
                {
                    row[col] = 0;
                }
            }
        }

        if (matrix.front().front() == 0) fill(matrix.front().begin(), matrix.front().end(), 0);
        if (col0)
        {
            for (auto& row: matrix)
            {
                row.front() = 0;
            }
        }
    }
};
