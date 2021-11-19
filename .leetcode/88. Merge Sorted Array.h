class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        vector<int> result;
        {
            auto it1 = nums1.begin(), it2 = nums2.begin(),
                end1 = nums1.begin() + m, end2 = nums2.begin() + n;
            while (true)
            {
                if (it1 == end1)
                {
                    for (; it2 != end2; ++it2)
                    {
                        result.push_back(*it2);
                    }
                    break;
                }
                if (it2 == end2)
                {
                    for (; it1 != end1; ++it1)
                    {
                        result.push_back(*it1);
                    }
                    break;
                }
                if (*it1 < *it2)
                {
                    result.push_back(*it1);
                    ++it1;
                }
                else
                {
                    result.push_back(*it2);
                    ++it2;
                }
            }
        }
        nums1 = result;
    }
};
