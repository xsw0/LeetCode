class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        auto l = lower_bound(
            intervals.begin(),
            intervals.end(),
            newInterval.front(),
            [](const vector<int>& element, int value)
            {
                return element.back() < value;
            });

        if (l == intervals.end())
        {
            intervals.push_back(newInterval);
            return intervals;
        }

        auto r = upper_bound(
            l,
            intervals.end(),
            newInterval.back(),
            [](int value, const vector<int>& element)
            {
                return value < element.front();
            });

        if (l == r)
        {
            intervals.insert(l, newInterval);
            return intervals;
        }

        if (distance(l, r) * 32 < newInterval.size())
        {
            if (newInterval.front() < l->front()) l->front() = newInterval.front();

            l->back() = prev(r)->back();
            if (newInterval.back() > l->back()) l->back() = newInterval.back();

            intervals.erase(next(l), r);
            return intervals;
        }

        vector<vector<int>> result;
        result.reserve(intervals.size() + l - r + 1);

        std::move(intervals.begin(), l, back_inserter(result));
        result.push_back({ min(l->front(), newInterval.front()), max(prev(r)->back(), newInterval.back()) });
        std::move(r, intervals.end(), back_inserter(result));
        return result;
    }
};
