class Solution
{
    string hash(const string& s)
    {
        string result;
        result.reserve(s.size());
        array<uint8_t, 26> arr{};
        for (auto c: s)
        {
            ++arr[c - 'a'];
        }
        for (size_t i = 0; i < arr.size(); ++i)
        {
            result.resize(result.size() + arr[i], 'a' + i);
        }
        return result;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> um;
        for (const auto& s: strs)
        {
            um[hash(s)].push_back(s);
        }
        vector<vector<string>> result;
        result.reserve(um.size());
        for (const auto& p: um)
        {
            result.emplace_back(p.second);
        }
        return result;
    }
};
