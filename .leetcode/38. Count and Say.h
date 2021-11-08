class Solution
{
public:
    string countAndSay(int n)
    {
        auto f = [=](const string& s)
        {
            string result;
            char say = s.front();
            int count = 0;
            for (auto c: s)
            {
                if (c == say)
                {
                    count++;
                }
                else
                {
                    result += to_string(count) + say;
                    say = c;
                    count = 1;
                }
            }
            result += to_string(count) + say;
            return result;
        };
        string result = "1";
        for (size_t i = 1; i < n; i++)
        {
            result = f(result);
        }
        return result;
    }
};
