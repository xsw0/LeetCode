class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        auto l = nums.begin();
        auto r = nums.rbegin();
        while (l != r.base())
        {
            if (*l != val)
            {
                l++;
            }
            else if (*r == val)
            {
                r++;
            }
            else
            {
                auto t = *l;
                *l = *r;
                *r = t;
            }
        }
        return l - nums.begin();
    }
};
