void array_bubble_sort(int *data, size_t n) {
  for (size_t i = 0; i < n - 1; ++i) {
    for (size_t j = n - 1; j > i; --j) {
      if (data[j] < data[j - 1]) {
        array_swap(data, j, j - 1);
      }
    }
  }
}
