class Solution
{
public:
    int numTrees(int n)
    {
        static map<int, int> m{
            { 0, 1 },
            { 1, 1 },
        };
        auto it = m.find(n);
        if (m.find(n) == m.end())
        {
            int sum = 0;
            for (int i = 1; i <= n; ++i)
            {
                sum += numTrees(i - 1) * numTrees(n - i);
            }

            it = m.insert({ n, sum }).first;
        }
        return it->second;
    }
};
