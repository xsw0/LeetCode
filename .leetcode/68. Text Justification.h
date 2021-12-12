class Solution
{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        size_t width = maxWidth;

        vector<string> result;
        result.reserve(words.size());

        result.emplace_back();
        result.back().reserve(width);
        result.back() += words.front();

        auto start = words.cbegin();
        auto length = words.front().size();

        for (auto current = next(words.cbegin()); current != words.cend(); ++current)
        {
            if (length + 1 + current->size() > width)
            {
                ++start;
                size_t count = distance(start, current);
                size_t spaces = width - length + count;
                while (start != current)
                {
                    result.back().resize(result.back().size() + (spaces + count - 1) / count, ' ');
                    spaces -= (spaces + count - 1) / count;
                    result.back() += *start;
                    --count;
                    ++start;
                }
                result.back().resize(width, ' ');

                result.emplace_back();
                result.back().reserve(width);
                result.back() += *current;
                length = current->size();
            }
            else
            {
                length += 1 + current->size();
            }
        }
        ++start;
        while (start != words.cend())
        {
            result.back().push_back(' ');
            result.back() += *start;
            ++start;
        }
        result.back().resize(width, ' ');
        return result;
    }
};
