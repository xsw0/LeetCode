#ifndef __TO_STRING_H__
#define __TO_STRING_H__

#include <string>

// #include <array>
// #include <vector>
// #include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>

namespace TO_STRING
{
    extern std::string emptyString; // Do not modify this variable

    extern size_t CONSOLE_WIDTH;

    extern std::string stringPrefix;
    extern std::string stringSuffix;
    extern std::string stringIndent;

    extern std::string arrayPrefix;
    extern std::string arraySuffix;
    extern std::string arraySeparator;
    extern std::string arraySpace;
    extern std::string arrayNewline;
    extern std::string arrayIndent;

    template <template <typename...> class>
    int prefix;
    template <template <typename...> class>
    int suffix;
    template <template <typename...> class>
    int separator;
    template <template <typename...> class>
    int space;
    template <template <typename...> class>
    int newline;
    template <template <typename...> class>
    int indent;

#define DECLARE(container)                   \
    template <>                              \
    extern std::string prefix<container>;    \
    template <>                              \
    extern std::string suffix<container>;    \
    template <>                              \
    extern std::string separator<container>; \
    template <>                              \
    extern std::string space<container>;     \
    template <>                              \
    extern std::string newline<container>;   \
    template <>                              \
    extern std::string indent<container>;

    DECLARE(std::vector);
    DECLARE(std::deque);
    DECLARE(std::forward_list);
    DECLARE(std::list);
    DECLARE(std::set);
    DECLARE(std::map);
    DECLARE(std::multiset);
    DECLARE(std::multimap);
    DECLARE(std::unordered_set);
    DECLARE(std::unordered_map);
    DECLARE(std::unordered_multiset);
    DECLARE(std::unordered_multimap);
    DECLARE(std::stack);
    DECLARE(std::queue);

    DECLARE(std::pair);
#undef DECLARE
} // namespace TO_STRING

inline std::string operator*(const std::string &s, size_t times)
{
    std::string result;
    result.reserve(s.size() * times);
    for (size_t i = 0; i < times; i++)
    {
        result += s;
    }
    return result;
}

inline std::string operator*(size_t times, const std::string &s)
{
    return s * times;
}

inline std::string tolower(const std::string &s)
{
    std::string result(s);
    for (auto &x : result)
    {
        x = std::tolower(x);
    }
    return result;
}

inline std::string toupper(const std::string &s)
{
    std::string result(s);
    for (auto &x : result)
    {
        x = std::toupper(x);
    }
    return result;
}

inline std::string to_string(const std::string &s,
                             std::string &indents = TO_STRING::emptyString)
{
    return indents + std::string(TO_STRING::stringPrefix) + s + std::string(TO_STRING::stringSuffix);
}

template <typename T>
std::string to_string(const T &x,
                      std::string &indents = TO_STRING::emptyString);

template <typename... T>
std::string to_string(const std::pair<T...> &p,
                      std::string &indents = TO_STRING::emptyString);

template <typename T, size_t size>
std::string to_string(const std::array<T, size> &,
                      std::string &indents = TO_STRING::emptyString);

template <typename T, typename Container = std::deque<T>>
std::string to_string(std::stack<T, Container> x, std::string &indents = TO_STRING::emptyString);

template <typename T, typename Container = std::deque<T>>
std::string to_string(std::queue<T, Container> x, std::string &indents = TO_STRING::emptyString);

template <template <typename...> class T, typename ForwardIt>
std::string to_string(ForwardIt first,
                      ForwardIt last,
                      std::string &indents = TO_STRING::emptyString);

#define DeclForwardItContainer(container)           \
    template <typename... T>                        \
    std::string to_string(const container<T...> &x, \
                          std::string &indents = TO_STRING::emptyString);

DeclForwardItContainer(std::vector);
DeclForwardItContainer(std::deque);
DeclForwardItContainer(std::forward_list);
DeclForwardItContainer(std::list);
DeclForwardItContainer(std::set);
DeclForwardItContainer(std::map);
DeclForwardItContainer(std::multiset);
DeclForwardItContainer(std::multimap);
DeclForwardItContainer(std::unordered_set);
DeclForwardItContainer(std::unordered_map);
DeclForwardItContainer(std::unordered_multiset);
DeclForwardItContainer(std::unordered_multimap);
#undef DeclForwardItContainer

template <typename T>
std::string to_string(const T &x, std::string &indents)
{
    return indents + std::to_string(x);
}

#define DefForwardItContainer(container)                                       \
    template <typename... T>                                                   \
    std::string to_string(const container<T...> &x, std::string &indents)      \
    {                                                                          \
        return to_string<container,                                            \
                         typename container<T...>::const_iterator>(x.cbegin(), \
                                                                   x.cend(),   \
                                                                   indents);   \
    }

DefForwardItContainer(std::vector);
DefForwardItContainer(std::deque);
DefForwardItContainer(std::forward_list);
DefForwardItContainer(std::list);
DefForwardItContainer(std::set);
DefForwardItContainer(std::map);
DefForwardItContainer(std::multiset);
DefForwardItContainer(std::multimap);
DefForwardItContainer(std::unordered_set);
DefForwardItContainer(std::unordered_map);
DefForwardItContainer(std::unordered_multiset);
DefForwardItContainer(std::unordered_multimap);
#undef DefForwardItContainer

template <typename... T>
std::string to_string(const std::pair<T...> &p,
                      std::string &indents)
{
    using namespace TO_STRING;
    std::string result;

    result += indents;
    result += prefix<std::pair>;
    {
        std::string s;
        result += to_string(p.first, s);
    }
    result += separator<std::pair>;
    result += space<std::pair>;
    {
        std::string s;
        result += to_string(p.second, s);
    }
    result += suffix<std::pair>;

    if (result.size() < CONSOLE_WIDTH)
    {
        return result;
    }
    else
    {
        std::string result;
        result += indents;
        result += prefix<std::pair>;
        result += newline<std::pair>;
        indents += indent<std::pair>;
        result += to_string(p.first, indents);
        result += separator<std::pair>;
        result += newline<std::pair>;
        result += to_string(p.second, indents);
        result += separator<std::pair>;
        result += newline<std::pair>;
        indents.erase(indents.size() - indent<std::pair>.size());
        result += indents;
        result += suffix<std::pair>;
        return result;
    }
}

template <typename T, size_t size>
std::string to_string(const std::array<T, size> &arr, std::string &indents)
{
    using namespace TO_STRING;
    if (arr.cbegin() == arr.cend())
    {
        return indents + arrayPrefix + arraySuffix;
    }
    else
    {
        std::string result;
        result += indents;
        result += arrayPrefix;
        auto it = arr.cbegin();
        for (; std::next(it) != arr.cend(); ++it)
        {
            std::string s;
            result += to_string(*it, s);
            result += arraySeparator;
            result += arraySpace;
        }
        std::string s;
        result += to_string(*it, s);
        result += arraySuffix;

        if (result.size() < CONSOLE_WIDTH)
        {
            return result;
        }
        else
        {
            std::string result(indents + arrayPrefix + arrayNewline);
            indents += arrayIndent;
            auto it = arr.cbegin();
            for (; std::next(it) != arr.cend(); ++it)
            {
                result += to_string(*it, indents);
                result += arraySeparator;
                result += arrayNewline;
            }
            result += to_string(*it, indents);
            result += arrayNewline;
            indents.erase(indents.size() - arrayIndent.size());
            return result + indents + arraySuffix;
        }
    }
}

template <template <typename...> class T, typename ForwardIt>
std::string to_string(ForwardIt first,
                      ForwardIt last,
                      std::string &indents)
{
    using namespace TO_STRING;
    if (first == last)
    {
        return indents + prefix<T> + suffix<T>;
    }
    else
    {
        std::string result;
        result += indents;
        result += prefix<T>;
        auto it = first;
        for (; std::next(it) != last; ++it)
        {
            std::string s;
            result += to_string(*it, s);
            result += separator<T>;
            result += space<T>;
        }
        std::string s;
        result += to_string(*it, s);
        result += suffix<T>;

        if (result.size() < CONSOLE_WIDTH)
        {
            return result;
        }
        else
        {
            std::string result(indents + prefix<T> + newline<T>);
            indents += indent<T>;
            auto it = first;
            for (; std::next(it) != last; ++it)
            {
                result += to_string(*it, indents);
                result += separator<T>;
                result += newline<T>;
            }
            result += to_string(*it, indents);
            result += newline<T>;
            indents.erase(indents.size() - indent<T>.size());
            return result + indents + suffix<T>;
        }
    }
}

template <typename T, typename Container>
std::string to_string(std::stack<T, Container> x, std::string &indents)
{
    std::deque<T> container;
    while (!x.empty())
    {
        container.push_front(x.top());
        x.pop();
    }
    return to_string<std::stack, typename std::deque<T>::iterator>(container.begin(), container.end(), indents);
}

template <typename T, typename Container>
std::string to_string(std::queue<T, Container> x, std::string &indents)
{
    std::deque<T> container;
    while (!x.empty())
    {
        container.push_back(x.front());
        x.pop();
    }
    return to_string<std::queue, typename std::deque<T>::iterator>(container.begin(), container.end(), indents);
}

#endif
