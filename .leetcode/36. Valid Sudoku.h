class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        array<array<bool, 9>, 9> rows{}, cols{}, boxes{};

        for (size_t i = 0; i < board.size(); ++i)
        {
            for (size_t j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] != '.')
                {
                    if (rows[i][board[i][j] - '1']) return false;
                    rows[i][board[i][j] - '1'] = true;

                    if (cols[j][board[i][j] - '1']) return false;
                    cols[j][board[i][j] - '1'] = true;

                    if (boxes[i / 3 * 3 + j / 3][board[i][j] - '1']) return false;
                    boxes[i / 3 * 3 + j / 3][board[i][j] - '1'] = true;
                }
            }
        }
        return true;
    }
};
