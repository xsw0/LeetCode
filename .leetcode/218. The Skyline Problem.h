class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        map<int, int> height{{ numeric_limits<int>::min(), 0 }};
        for (auto& building: buildings)
        {
            auto r = height.lower_bound(building[1]);
            if (r == height.end() || r->first != building[1])
            {
                assert(r != height.begin());
                r = height.insert(r, { building[1], prev(r)->second });
            }

            auto l = height.lower_bound(building[0]);
            if (l == height.end() || l->first != building[0])
            {
                assert(l != height.begin());
                l = height.insert(l, { building[0], prev(l)->second });
            }

            auto it = l;
            while (it != r)
            {
                if (it->second < building[2])
                {
                    if (it != height.begin() && prev(it)->second == building[2])
                    {
                        if (it == l)
                        {
                            l = it = height.erase(it);
                        }
                        else
                        {
                            it = height.erase(it);
                        }
                    }
                    else
                    {
                        it->second = building[2];
                        ++it;
                    }
                }
                else
                {
                    ++it;
                }
            }

            if (r != height.end() && r->second == building[2])
            {
                assert(l != r);
                height.erase(r);
            }
            assert(l != height.end());
            if (l != height.begin() && l->second == prev(l)->second)
            {
                height.erase(l);
            }
        }
        if (height.begin()->second == 0) { height.erase(height.begin()); }

        vector<vector<int>> result;
        result.reserve(height.size());
        for (auto p: height)
        {
            if (result.empty() || result.back().back() != p.second)
            {
                result.emplace_back(vector<int>{ p.first, p.second });
            }
        }
        return result;
    }
};
