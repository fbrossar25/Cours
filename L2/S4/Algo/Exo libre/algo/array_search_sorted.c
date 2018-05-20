size_t array_search_sorted(const int *data, size_t n,
                                                   int e) {
  return array_binary_search(data, n, e, 0, n);
}
