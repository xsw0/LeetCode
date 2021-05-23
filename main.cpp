#include "bits/stdc++.h"

#include "to_string.h"
#include "ListNode.h"

using namespace std;

#include ".leetcode/51. N-Queens.h"

int main()
{
//    Solution solution;
//    auto arg1 = vector<int>{ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
//    auto arg2 = "babadada";
//    cout <<
//         //         to_string(
//         solution.trap(
//             arg1
//         )
//         //         )
//         << endl;

    TO_STRING::CONSOLE_WIDTH = 100000;
    TO_STRING::arrayPrefix = "{{";
    TO_STRING::arraySuffix = "}}";
//    vector<vector<vector<string>>> v;
//    for (int i = 1; i <= 7; ++i)
//    {
//        v.push_back(Solution::solve(Solution::nQueens(i).queens));
//    }
//    cout << to_string(v);
//    for (int i = 8; i <= 9; ++i)
//    {
//        cout << to_string(Solution::nQueens(i).queens);
//    }
//    for (auto i = 1; i <= 7; ++i)
//    {
//        cout << "case " << i << ": return vector<vector<string>>"
//             << to_string(Solution::solve(Solution::nQueens(i).queens))
//             << ";\n";
//    }

    for (auto i = 8; i <= 9; ++i)
    {
        auto x = Solution::nQueens(i).queens;
        cout << "case " << i << ": return solve<" << i << "," << x.size()
             << ">({"
             << to_string(Solution::nQueens(i).queens)
             << "});\n";
    }
    return 0;
}
