class Solution
{
    struct Building
    {
        int left;
        int right;
        int height;

        Building(const vector<int>& v) : left{ v[0] }, right{ v[1] }, height{ v[2] } {}

        bool operator<(const Building& rhs) const
        {
            return height < rhs.height ||
                   (height == rhs.height && right < rhs.right);
        }
    };

public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        vector<vector<int>> result{{ buildings.front().front(), 0 }};

        priority_queue<Building> pq;

        int right = 0;

        for (Building build: buildings)
        {
            while (!pq.empty() && pq.top().right <= build.left)
            {
                if (pq.top().right > result.back().front())
                {
                    if (pq.top().height > result.back().back())
                    {
                        if (result.size() > 1 && result[result.size() - 2].back() == pq.top().height)
                        {
                            result.pop_back();
                        }
                        else
                        {
                            result.back().back() = pq.top().height;
                        }
                    }
                    if (pq.top().height == result.back().back())
                    {
                        result.push_back({ pq.top().right, 0 });
                    }
                }
                pq.pop();
            }

            if (pq.empty() || build.height > pq.top().height)
            {
                if (build.left == result.back().front())
                {
                    if (result.size() > 1 && result[result.size() - 2].back() == build.height)
                    {
                        result.pop_back();
                    }
                    else
                    {
                        result.back().back() = build.height;
                    }
                }
                else
                {
                    result.push_back({ build.left, build.height });
                }
            }

            pq.push(build);
        }

        while (!pq.empty())
        {
            if (pq.top().right > result.back().front())
            {
                if (pq.top().height > result.back().back())
                {
                    if (result.size() > 1 && result[result.size() - 2].back() == pq.top().height)
                    {
                        result.pop_back();
                    }
                    else
                    {
                        result.back().back() = pq.top().height;
                    }
                }
                if (pq.top().height == result.back().back())
                {
                    result.push_back({ pq.top().right, 0 });
                }
            }
            pq.pop();
        }

        return result;
    }
};


