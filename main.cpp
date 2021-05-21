#include <variant>

#include "bits/stdc++.h"
#include "ListNode.h"
#include "to_string.h"

using namespace std;

#include ".leetcode/57. Insert Interval.h"

using return_t = int;

int main()
{
    Solution solution;

    auto arg1 = vector<vector<int>>{
        { 1, 5 }
    };
    auto arg2 = vector<int>{ 5, 7 };

    cout <<
         to_string(solution.insert(arg1, arg2))
         << endl;
    return 0;
}
