#ifndef INCLUDED_ARRAY_TWO_POINTERS_MERGE_SORTED_ARRAY_WITHOUT_DUPLICATES
#define INCLUDED_ARRAY_TWO_POINTERS_MERGE_SORTED_ARRAY_WITHOUT_DUPLICATES

namespace other_resource {

std::vector<int>
  merge_two_sorted_arrays_without_duplicates(std::vector<int> &l,
                                             std::vector<int> &r)
{
  std::vector<int> sorted;
  sorted.reserve(l.size() + r.size());

  int i = 0, j = 0;

  while (i < l.size() && j < r.size())
  {
    auto &x = l[i];
    auto &y = r[j];

    int next = std::min(x, y);

    if (sorted.empty() || sorted.back() != next)
      sorted.push_back(next);

    if (x > y) ++j;
    else       ++i;
  }

  for (auto k = i; k < l.size(); ++k)
    if (sorted.empty() || sorted.back() != l[k])
      sorted.push_back(l[k]);

  for (auto k = j; k < r.size(); ++k)
    if (sorted.empty() || sorted.back() != r[k])
      sorted.push_back(r[k]);

  return sorted;
}

} // end namespace other_resource

#endif