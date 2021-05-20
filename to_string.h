//
// Created by 0x0 on 5/18/21.
//

#ifndef LEETCODE__TO_STRING_H_
#define LEETCODE__TO_STRING_H_

#include <iostream>

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<T>> &v);

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v);

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<T>> &v)
{
    if (v.empty())
    {
        os << "{}";
    }
    else
    {
        os << "{\n    " << v.front();
        for (auto it = next(v.cbegin()); it != v.cend(); ++it)
        {
            os << ",\n    " << *it;
        }
        os << "\n}";
    }
    return os;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    if (v.empty())
    {
        os << "{}";
    }
    else
    {
        os << '{' << v.front();
        for (auto it = next(v.cbegin()); it != v.cend(); ++it)
        {
            os << ' ' << *it;
        }
        os << '}';
    }
    return os;
}

#endif //LEETCODE__TO_STRING_H_
