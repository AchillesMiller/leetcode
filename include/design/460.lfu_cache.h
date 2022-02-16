#ifndef INCLUDED_DESIGN_460_LFU_CACHE
#define INCLUDED_DESIGN_460_LFU_CACHE

namespace leetcode {

class LFUCache {
public:
  LFUCache(int capacity)
  : _capacity(capacity)
  , _min_freq(0)
  {}

  int get(int key) {
    return get_impl(key);
  }

  void put(int key, int value) {

    if (_capacity == 0)
      return;

    auto &val = get_impl(key);

    if (val != -1)
    {
      val = value;
      return;
    }

    if (_key2val.size() == _capacity)
    {
      auto &minf = _freqs[_min_freq];
      assert (!minf.empty());

      _key2val.erase(minf.front().key);
      minf.pop_front();
    }

    _freqs[1].push_back(std::move(node(key, value, 1)));
    _key2val[key] = std::prev(_freqs[1].end(), 1);
    _min_freq = 1;
  }

private:

  struct node
  {
    int key;
    int val;
    int fre;

    node(int k, int v, int f) : key(k), val(v), fre(f) {}

    node (node && n)
    : key(std::move(n.key))
    , val(std::move(n.val))
    , fre(std::move(n.fre))
    {}
  };

  using list_t = std::list<node>;
  using iterator_t = typename list_t::iterator;

  std::unordered_map<int, list_t> _freqs;
  //                 ---- -------
  //                 freq  list

  std::unordered_map<int, iterator_t> _key2val;

  int _capacity;
  int _min_freq;

  int & get_impl(int key)
  {
    auto found = _key2val.find(key);
    if (found == _key2val.end())
    {
      static int non_found = -1;
      return non_found;
    }

    auto it = found->second;

    auto &n = *it;
    int fre = n.fre;
    n.fre ++;

    // insert it to next freq
    _freqs[fre+1].push_back(std::move(n));
    _freqs[fre].erase(it);

    if (_min_freq == fre && _freqs[fre].empty())
      _min_freq = fre+1;

    // reset map
    _key2val[key] = std::prev(_freqs[fre+1].end(), 1);

    return _freqs[fre+1].back().val;
  }


  // basically, both get and put should be O(1)
  // therefore, there must be some hash map exists
  // freq    1        2      3     4
  //     (k1, k2) (k3, k4)  (k5) (kn)

  // if the number of keys exceed the capacity, we want to erase the min freq
  // min_freq is set to be zero in the beginning,

  // for get, once one key is accessed, the freq ++; and if min_freq doesn't
  // have any keys associated with it, increase min_freq
  // for put, it is possible to erase the key of min_freq,
  // but after put a new element, the min_freq will be reset to be 1

};

} // end namespace leetcode

#endif