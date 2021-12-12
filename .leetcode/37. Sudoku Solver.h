class Solution
{
    static bool isValid(vector<vector<char>>& board, size_t row, size_t col, char c)
    {
        for (size_t i = 0; i < 9; ++i)
        {
            if (board[row][i] == c) return false;
            if (board[i][col] == c) return false;
            if (board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == c) return false;
        }
        return true;
    }

    vector<vector<char>>* board = nullptr;

    bool solve(size_t index = 0)
    {
        if (index > 80) return true;

        size_t x = index / 9;
        size_t y = index % 9;

        if ((*board)[x][y] == '.')
        {
            for (char c = '1'; c <= '9'; ++c)
            {
                if (isValid((*board), x, y, c))
                {
                    (*board)[x][y] = c;
                    if (solve(index + 1)) return true;
                }
            }
            (*board)[x][y] = '.';
            return false;
        }
        else
        {
            return solve(index + 1);
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        this->board = &board;
        solve();
        this->board = nullptr;
    }
};
