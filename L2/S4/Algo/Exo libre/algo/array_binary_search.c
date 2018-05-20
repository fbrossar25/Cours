size_t array_binary_search(const int *data, size_t n,
                             int e, size_t lo, size_t hi) {
  if (lo == hi) {
    return n;
  }
  size_t mid = (lo + hi) / 2;
  if (e < data[mid]) {
    return array_binary_search(data, n, e, lo, mid);
  }
  if (data[mid] < e) {
    return array_binary_search(data, n, e, mid + 1, hi);
  }
  return mid;
}
