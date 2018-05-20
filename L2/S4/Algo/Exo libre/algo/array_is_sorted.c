bool array_is_sorted(int *data, size_t n) {
  for (int i = 1; i < n; ++i) {
    if (data[i - 1] > data[i]) {
      return false;
    }
  }
  return true;
}
