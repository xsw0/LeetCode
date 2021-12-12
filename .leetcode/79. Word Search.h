#include <utility>

class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        auto m = board.size();
        auto n = board.front().size();
        Dfs dfs{ board, word, m, n };
        for (size_t i = 0; i != m; ++i)
        {
            assert(board[i].size() == n);
            for (size_t j = 0; j != n; ++j)
            {
                if (dfs.dfs(i, j)) return true;
            }
        }
        return false;
    }

private:
    struct Dfs
    {
        vector<vector<char>>& board;
        string& word;
        size_t m;
        size_t n;

        bool dfs(size_t x, size_t y) { return dfs(x, y, word.begin()); }
        bool dfs(size_t x, size_t y, string::iterator it)
        {
            if (*it != board[x][y]) return false;
            ++it;
            if (it == word.cend()) return true;
            board[x][y] = '\0';
            if (x != 0 && dfs(x - 1, y, it) ||
                y != 0 && dfs(x, y - 1, it) ||
                x + 1 != m && dfs(x + 1, y, it) ||
                y + 1 != n && dfs(x, y + 1, it))
                return true;
            --it;
            board[x][y] = *it;
            return false;
        }
    };
};
