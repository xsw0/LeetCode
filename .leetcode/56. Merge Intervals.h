class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.reserve(intervals.size());
        result.push_back(intervals.front());
        for (auto it = next(intervals.cbegin()); it != intervals.cend(); ++it)
        {
            if (result.back().back() < it->front())
            {
                result.emplace_back(*it);
            }
            else if (result.back().back() < it->back())
            {
                result.back().back() = it->back();
            }
        }
        return result;
    }

//    vector<vector<int>> merge(vector<vector<int>>& intervals)
//    {
//        map<int, int> m;
//
//        for (auto& v : intervals)
//        {
//            assert(v.size() == 2);
//            auto start = v.front();
//            auto end = v.back();
//            auto l = m.lower_bound(start);
//            if (l != m.begin() && prev(l)->second >= start) --l;
//            auto r = m.upper_bound(end);
//            if (l != m.end() && l->first < start) start = l->first;
//            if (r != m.begin() && prev(r)->second > end) end = prev(r)->second;
//            while (l != r) l = m.erase(l);
//            m.insert({ start, end });
//        }
//
//        vector<vector<int>> result;
//        result.reserve(m.size());
//        for (auto p : m)
//        {
//            result.push_back({ p.first, p.second });
//        }
//
//        return result;
//    }
};
