class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        int count = 0;
        int Majority;
        for (auto num: nums)
        {
            if (count == 0)
            {
                Majority = num;
                ++count;
            }
            else
            {
                Majority == num ? ++count : --count;
            }
        }
        return Majority;
    }
};
