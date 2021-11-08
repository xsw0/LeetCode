class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        auto zero = nums.begin();
        auto one = nums.begin();
        auto two = nums.end();
        while (one != two)
        {
            switch (*one)
            {
            case 0:
                swap(*zero, *one);
                ++zero;
                ++one;
                break;
            case 1:
                ++one;
                break;
            case 2:
                --two;
                swap(*one, *two);
                break;
            default:
                assert(0);
            }
        }
    }
};
