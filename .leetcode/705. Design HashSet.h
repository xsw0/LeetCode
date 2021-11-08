class MyHashSet
{
    static constexpr int Prime = 24593;
    static constexpr int NullFlag = -1;
    std::array<int, Prime> arr;

    std::array<int, Prime>::iterator find(
        std::array<int, Prime>::iterator first,
        std::function<bool(int)> pFunction)
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

    std::list<int> takeOut(
        std::array<int, Prime>::iterator first,
        std::array<int, Prime>::iterator last)
    {
        std::list<int> result;
        if (first < last)
        {
            while (first != last)
            {
                result.push_back(*first);
                *first = NullFlag;
                ++first;
            }
        }
        else
        {
            for (; first != arr.end(); ++first)
            {
                result.push_back(*first);
                *first = NullFlag;
                ++first;
            }
            first = arr.begin();
            for (; first != last; ++first)
            {
                result.push_back(*first);
                *first = NullFlag;
                ++first;
            }
        }
        return result;
    }

public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
        arr.fill(NullFlag);
    }

    void add(int key)
    {
        std::function<bool(int)> f = [=](int n) -> bool
        {
            return n == NullFlag || n == key;
        };
        auto it = find(arr.begin() + key % Prime, f);
        assert(it != arr.end());
        *it = key;
    }

    void remove(int key)
    {
        std::function<bool(int)> f = [=](int n) -> bool
        {
            return n == NullFlag || n == key;
        };
        auto it = find(arr.begin() + key % Prime, f);
        if (*it == NullFlag) return;
        auto end = find(it, [](int n) { return n == NullFlag; });
        auto l = takeOut(it, end);
        l.pop_front();
        while (!l.empty())
        {
            add(l.front());
            l.pop_front();
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        std::function<bool(int)> f = [=](int n) -> bool
        {
            return n == NullFlag || n == key;
        };
        auto it = find(arr.begin() + key % Prime, f);
        return *it != NullFlag;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
