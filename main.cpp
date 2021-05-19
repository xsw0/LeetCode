#include "bits/stdc++.h"
#include "ListNode.h"
#include "to_string.h"

using namespace std;

#include ".leetcode/30. Substring with Concatenation of All Words.h"

int main()
{
    Solution solution;
    vector<string> v{ "foo", "bar" };
    auto result = solution.findSubstring("barfoothefoobarman", v);
    cout << result << endl;
    return 0;
}
