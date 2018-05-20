void array_merge(int *data, size_t i, size_t m, size_t j,
                                                int *tmp) {
  size_t a = i;
  size_t b = m;
  for (size_t k = i; k < j; ++k) {
    if (a < m && (b == j || data[a] < data[b])) {
      tmp[k] = data[a];
      a++;
    } else {
      tmp[k] = data[b];
      b++;
    }
  }
}
