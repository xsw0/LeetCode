class Solution
{
public:
    string simplifyPath(string path)
    {
        const char* start = path.c_str();
        const char* current = path.c_str();
        auto entry = [&]()
        {
            while (*current == '/') ++current;
            start = current;
            while (*current != '\0' && *current != '/') ++current;
            return start != current;
        };
        list<string_view> l;
        while (entry())
        {
            size_t size = current - start;
            string_view view{ start, size };
            if (view != ".")
            {
                if (view != "..")
                {
                    l.emplace_back(view);
                }
                else
                {
                    if (!l.empty()) l.pop_back();
                }
            }
        }
        string result;
        result.reserve(path.size());
        for (auto& view: l)
        {
            result.push_back('/');
            result += view;
        }
        return result.empty() ? "/" : result;
    }
};
