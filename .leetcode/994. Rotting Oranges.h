class Solution
{
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        size_t rows = grid.size();
        size_t cols = grid.front().size();
        int fresh = 0;
        vector<pair<size_t, size_t>> rotten;
        rotten.reserve(rows * cols);
        for (size_t i = 0; i != rows; ++i)
        {
            assert(grid[i].size() == cols);
            for (size_t j = 0; j != cols; ++j)
            {
                switch (grid[i][j])
                {
                case 1:
                    ++fresh;
                    break;
                case 2:
                    rotten.emplace_back(i, j);
                    break;
                default:
                    break;
                }
            }
        }
        int time = 0;
        while (fresh != 0 && !rotten.empty())
        {
            vector<pair<size_t, size_t>> new_rotten;
            new_rotten.reserve(fresh);
            for (auto p: rotten)
            {
                auto f = [&](size_t x, size_t y)
                {
                    if (x < rows && y < cols && grid[x][y] == 1)
                    {
                        --fresh;
                        grid[x][y] = 2;
                        new_rotten.emplace_back(x, y);
                    }
                };
                f(p.first - 1, p.second);
                f(p.first + 1, p.second);
                f(p.first, p.second - 1);
                f(p.first, p.second + 1);
            }
            rotten = new_rotten;
            ++time;
        }
        return fresh == 0 ? time : -1;
    }
};
