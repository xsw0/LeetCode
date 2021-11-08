class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> nums;
        nums.reserve(nums1.size() + nums2.size());
        nums.insert(nums.end(), nums1.begin(), nums1.end());
        nums.insert(nums.end(), nums2.begin(), nums2.end());
        sort(nums.begin(), nums.end());
        return static_cast<double>(nums[(nums.size() - 1) / 2] + nums[nums.size() / 2]) / 2;
    }
};
