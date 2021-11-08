class Solution
{
public:
    bool search(vector<int>& nums, int target)
    {
        size_t l = 0;
        size_t r = nums.size();

        while (l < r)
        {
            size_t mid = l + (r - l) / 2;
            if (nums[mid] == target) return true;
            if (nums[l] < nums[mid])
            {
                if (target >= nums[l] && target < nums[mid]) r = mid;
                else l = mid + 1;
            }
            else if (nums[mid] < nums[r - 1])
            {
                if (target > nums[mid] && target <= nums[r - 1])l = mid + 1;
                else r = mid;
            }
            else
            {
                while (l != r && nums[l] == nums[mid]) ++l;
                while (l != r && nums[r - 1] == nums[mid]) --r;
            }
        }

        return false;
    }
};
