class Solution
{
 public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<unordered_set<char>, vector<string>> um;
        for (const auto &s :strs)
        {
            unordered_set<char> us{ s.cbegin(), s.cend() };
            um[us].push_back(s);
        }
        return vector<vector<string>>(um.cbegin(), um.cend());
    }
};
