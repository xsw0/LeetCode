class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        auto m = obstacleGrid.size();
        auto n = obstacleGrid.front().size();
        assert(m != 0);
        assert(n != 0);
        obstacleGrid.front().front() = !obstacleGrid.front().front();
        for (size_t col = 1; col < n; ++col)
        {
            if (obstacleGrid.front()[col] != 0)
            {
                obstacleGrid.front()[col] = 0;
            }
            else
            {
                obstacleGrid.front()[col] = obstacleGrid.front()[col - 1];
            }
        }
        for (size_t row = 1; row < m; ++row)
        {
            if (obstacleGrid[row].front() != 0)
            {
                obstacleGrid[row].front() = 0;
            }
            else
            {
                obstacleGrid[row].front() = obstacleGrid[row - 1].front();
            }
            assert(obstacleGrid[row].size() == n);
            for (int col = 1; col < n; ++col)
            {
                if (obstacleGrid[row][col] != 0)
                {
                    obstacleGrid[row][col] = 0;
                }
                else
                {
                    obstacleGrid[row][col] = obstacleGrid[row - 1][col] + obstacleGrid[row][col - 1];
                }
            }
        }
        return obstacleGrid.back().back();
    }
};
