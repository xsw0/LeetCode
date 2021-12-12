class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        --numRows;
        vector<vector<int>> pascal;
        pascal.reserve(numRows + 1);
        pascal.emplace_back(vector<int>{ 1 });
        for (size_t i = 0; i != numRows; ++i)
        {
            vector<int> row;
            row.reserve(i + 2);
            row.emplace_back(1);
            for (size_t j = 0; j != i; ++j)
            {
                row.emplace_back(pascal.back()[j] + pascal.back()[j + 1]);
            }
            row.emplace_back(1);
            pascal.emplace_back(row);
        }
        return pascal;
    }
};
