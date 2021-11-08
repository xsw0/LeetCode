class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        size_t left = 0;
        size_t right = nums.size();
        while (left != right)
        {
            size_t mid = (left + right) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};
