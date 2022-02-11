#ifndef INCLUDED_DESIGN_146_LRU_CACHE
#define INCLUDED_DESIGN_146_LRU_CACHE

namespace leetcode {


/** @brief: LRU Cache
 *  Design a data structure that follows
 *  the constraints of a Least Recently Used (LRU) cache.
 *
 *  Implement the LRUCache class:
 *    LRUCache(int capacity)
        Initialize the LRU cache with positive size capacity.
 *    int get(int key)
        Return the value of the key if the key exists, otherwise return -1.
 *    void put(int key, int value)
 *      Update the value of the key if the key exists.
 *      Otherwise, add the key-value pair to the cache.
 *      If the number of keys exceeds the capacity from this operation,
 *      evict the least recently used key
 **/

class LRUCache {

  // least recently used cache
  //   put/delete operations should be efficient, therefore list will be used
  //   get operation needs a hash map

  using data_t     = std::list<std::pair<int, int>>; // key, value
  using iterator_t = typename data_t::iterator;
  using cache_t    = std::unordered_map<int, iterator_t>;

private:
  int     _capacity;
  data_t  _data;
  cache_t _cache;  // priority low to high

public:
  LRUCache(int capacity) : _capacity(capacity), _data(), _cache() {}

  int get(int key)
  {
    auto found = _cache.find(key);
    if (found == _cache.end())
      return -1;

    int value = found->second->second;

    put(key, value);

    return value;
  }

  void put(int key, int value)
  {
    // put key and value to unordered map
    auto found = _cache.find(key);

    if (found != _cache.end()) // key is found, erase key and re-push
      _data.erase(found->second);

    _data.push_back(std::make_pair(key, value));

    _cache[key] = std::prev(_data.end(), 1);

    if (_data.size() == _capacity+1)
    {
      _cache.erase(_data.front().first);
      _data.pop_front();
    }
  }
};

} // end namespace leetcode


#endif