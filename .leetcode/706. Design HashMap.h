class MyHashMap
{
    using key_type = int;
    using mapped_type = int;
    using value_type = std::pair<key_type, mapped_type>;

    static constexpr int Prime = 24593;
    static constexpr key_type NullFlag = -1;

    static key_type hasher(key_type key)
    {
        return key % Prime;
    }

    static bool key_equal(key_type lhs, key_type rhs)
    {
        return lhs == rhs;
    }

    std::array<value_type, Prime> arr;

    std::array<value_type, Prime>::iterator
    find(std::array<value_type, Prime>::iterator first,
         const std::function<bool(value_type)>& pFunction)
    {
        auto it = first;
        for (; it < arr.end(); ++it)
        {
            if (pFunction(*it))
            {
                return it;
            }
        }
        it = arr.begin();
        for (; it < first; ++it)
        {
            if (pFunction(*it))
            {
                return it;
            }
        }
        return arr.end();
    }

    std::list<value_type> takeOut(std::array<value_type, Prime>::iterator first,
                                  std::array<value_type, Prime>::iterator last)
    {
        std::list<value_type> result;
        if (first < last)
        {
            while (first != last)
            {
                result.push_back(*first);
                *first = { NullFlag, NullFlag };
                ++first;
            }
        }
        else
        {
            for (; first != arr.end(); ++first)
            {
                result.push_back(*first);
                *first = { NullFlag, NullFlag };
                ++first;
            }
            first = arr.begin();
            for (; first != last; ++first)
            {
                result.push_back(*first);
                *first = { NullFlag, NullFlag };
                ++first;
            }
        }
        return result;
    }

public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
        arr.fill({ NullFlag, NullFlag });
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        std::function<bool(value_type)> f = [=](value_type n) -> bool
        {
            return key_equal(n.first, NullFlag) || key_equal(n.first, key);
        };
        auto it = find(arr.begin() + hasher(key), f);
        assert(it != arr.end());
        *it = { key, value };
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        std::function<bool(value_type)> f = [=](value_type n) -> bool
        {
            return key_equal(n.first, NullFlag) || key_equal(n.first, key);
        };
        auto it = find(arr.begin() + hasher(key), f);
        return key_equal(it->first, NullFlag) ? -1 : it->second;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        std::function<bool(value_type)> f = [=](value_type n) -> bool
        {
            return key_equal(n.first, NullFlag) || key_equal(n.first, key);
        };
        auto it = find(arr.begin() + hasher(key), f);
        if (key_equal(it->first, NullFlag)) return;
        auto end = find(it, [](value_type n) { return key_equal(n.first, NullFlag); });
        auto l = takeOut(it, end);
        l.pop_front();
        while (!l.empty())
        {
            put(l.front().first, l.front().second);
            l.pop_front();
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
