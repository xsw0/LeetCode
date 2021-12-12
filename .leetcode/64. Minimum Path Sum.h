class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        size_t m = grid.size();
        size_t n = grid.front().size();
        for (size_t col = 1; col < n; ++col)
        {
            grid.front()[col] += grid.front()[col - 1];
        }
        for (size_t row = 1; row < m; ++row)
        {
            grid[row].front() += grid[row - 1].front();

            assert(grid[row].size() == n);
            for (size_t col = 1; col < n; ++col)
            {
                grid[row][col] += min(grid[row - 1][col], grid[row][col - 1]);
            }
        }
        return grid.back().back();
    }
};
