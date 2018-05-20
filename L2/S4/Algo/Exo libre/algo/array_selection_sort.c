void array_selection_sort(int *data, size_t n) {
  for (size_t i = 0; i < n - 1; ++i) {
    size_t j = i;
    for (size_t k = j + 1; k < n; ++k) {
      if (data[k] < data[j]) {
        j = k;
      }
    }
    array_swap(data, i, j);
  }
}
