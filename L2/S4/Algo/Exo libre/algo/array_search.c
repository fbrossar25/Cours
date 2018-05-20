size_t array_search(const int *data, size_t n, int e) {
  size_t i = 0;
  while (i < n && data[i] != e) {
    i++;
  }
  return i;
}
