void array_counting_sort(int *data, size_t n, int m) {
  size_t *hist = calloc(m, sizeof(size_t));
  for (size_t i = 0; i < n; ++i) {
    hist[data[i]] += 1;
  }
  size_t j = 0;
  for (int val = 0; val < m; ++val) {
    for (size_t k = 0; k < hist[i]; ++k) {
      data[j] = val;
      j++;
    }
  }
  free(hist);
}
