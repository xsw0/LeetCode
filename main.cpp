#include "bits/stdc++.h"

#include "to_string.h"
#include "ListNode.h"

using namespace std;

#include ".leetcode/76. Minimum Window Substring.h"

int main()
{
    Solution solution;
    auto arg1 = vector<int>{ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    auto arg2 = "babadada";
    auto arg3 = vector<vector<int>>{
        { 1, 1 }
    };
    cout <<
         //         to_string(
         solution.minWindow(
             "ADOBECODEBANC",
             "ABC"
         )
         //         )
         << endl;
    return 0;
}
