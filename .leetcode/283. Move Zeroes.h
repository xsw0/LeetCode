class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
//        auto zero = nums.begin();
//        vector<int>::iterator non_zero;
//        while (true)
//        {
//            while (zero != nums.end() && *zero != 0) { ++zero; }
//            non_zero = zero;
//            while (non_zero != nums.end() && *non_zero == 0) { ++non_zero; }
//            if (non_zero == nums.end()) { break; }
//            swap(*zero, *non_zero);
//        }
        stable_sort(nums.begin(), nums.end(), [](int lhs, int rhs) -> bool
        {
            return lhs != 0 && rhs == 0;
        });
    }
};
