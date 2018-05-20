void array_insert(int *data, size_t m, int e, size_t j) {
  for (size_t i = m; i > j; --i) {
    data[i] = data[i - 1];
  }
  data[j] = e;
}
