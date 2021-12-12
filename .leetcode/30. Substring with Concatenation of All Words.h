class Solution
{
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        auto length = words.front().size();
        if (s.size() < length * words.size()) return {};

        vector<int> result;
        for (size_t i = 0; i < length; ++i)
        {
            unordered_map<string, size_t> um;
            for (auto& str: words)
            {
                ++um[str];
            }

            for (size_t j = i; j < length * words.size(); j += length)
            {
                string str = s.substr(j, length);
                --um[str];
                if (um[str] == 0) um.erase(str);
            }

            if (um.empty()) result.push_back(i);

            size_t jMax = s.size() - length * words.size();
            for (size_t j = i; j + length <= jMax; j += length)
            {
                string str;

                str = s.substr(j, length);
                ++um[str];
                if (um[str] == 0) um.erase(str);

                str = s.substr(j + length * words.size(), length);
                --um[str];
                if (um[str] == 0) um.erase(str);

                if (um.empty()) result.push_back(j + length);
            }
        }

        return result;
    }
};
