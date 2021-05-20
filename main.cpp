#include <variant>

#include "bits/stdc++.h"
#include "ListNode.h"
#include "to_string.h"

using namespace std;

#include ".leetcode/49. Group Anagrams.h"

int main()
{
    Solution solution;
    auto arg1 = vector<vector<int>>{{ 5, 1, 9, 11 }, { 2, 4, 8, 10 }, { 13, 3, 6, 7 }, { 15, 14, 12, 16 }};
    solution.rotate(arg1);
    cout << arg1 << endl;
    return 0;
}
