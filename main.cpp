#include <variant>

#include "bits/stdc++.h"
#include "ListNode.h"
//#include "to_string.h"

using namespace std;

template<typename It>
std::string ss(It first,
		It last,
		function<std::string(const typename std::iterator_traits<It>::value_type&)> p,
		const std::string& separator = ",")
{
	std::string result;
	if (first != last)
	{
		result += p(*first);
		++first;
		while (first != last)
		{
			result += separator + p(*first);
			++first;
		}
	}
	return result;
}

#include ".leetcode/51. N-Queens.h"

int main()
{
//    TO_STRING::CONSOLE_WIDTH = 10;
	Solution solution;

//    auto arg1 = vector<string>{ "eat", "tea", "tan", "ate", "nat", "bat" };
//    cout << arg1 << endl;
//    cout <<
//         to_string(solution.solveNQueens(1))
//         << endl;


	for (size_t i = 1; i <= 9; ++i)
	{
		nQueens nq{ i };
		nq.solve();
		cout << nq.to_string() << "," << endl << endl;
//        for (auto &board : nq.queens)
//        {
//            for (size_t row = 0; row < board.size(); ++row)
//            {
////                cout << " ( " << row << " " << board[row] << " ) ";
//            }
//            cout << endl;
//        }
	}
	return 0;
}
