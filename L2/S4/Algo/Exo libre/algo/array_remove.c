void array_remove(int *data, size_t n, size_t j) {
  for (size_t i = j + 1; i < n; ++i) {
    data[i - 1] = data[i];
  }
}
