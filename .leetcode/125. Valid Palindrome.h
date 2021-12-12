class Solution
{
public:
    bool isPalindrome(string s)
    {
        auto left = s.cbegin();
        auto right = s.cend();
        while (left < right)
        {
            while (left != right && !isalnum(*left)) { ++left; }
            while (left != right && !isalnum(*prev(right))) { --right; }
            if (left == right) { return true; }
            if (tolower(*left) != tolower(*prev(right))) { return false; }
            ++left;
            --right;
        }
        return true;
    }
};
