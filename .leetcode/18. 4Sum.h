class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        int preFirst = numeric_limits<int>::max();

        auto first = nums.cbegin();
        auto last = prev(nums.cend());

        while (first < last)
        {
            int64_t remaining64 = static_cast<int64_t>(target) - (*first + *last);
            if (remaining64 > 2e9)
            {
                ++first;
            }
            else if (remaining64 < -2e9)
            {
                --last;
            }
            else
            {
                if (*first != preFirst)
                {
                    preFirst = *first;
                    auto fourth = last;

                    int preFourth = numeric_limits<int>::min();
                    while (first < fourth && remaining64 <= 2e9)
                    {
                        if (*fourth != preFourth)
                        {
                            preFourth = *fourth;
                            auto second = next(first);
                            auto third = prev(fourth);
                            int remaining32 = remaining64;

                            while (second < third)
                            {
                                if (*second + *third > remaining32) { --third; }
                                else if (*second + *third < remaining32) { ++second; }
                                else
                                {
                                    result.push_back({ *first, *second, *third, *fourth });
                                    ++second, --third;
                                    while (second < third && *second == *prev(second) && *third == *next(third))
                                    {
                                        ++second, --third;
                                    }
                                }
                            }
                        }
                        --fourth;
                        remaining64 = static_cast<int64_t>(target) - (*first + *fourth);
                    }
                }
                ++first;
            }
        }
        return result;
    }
};
