void array_insertion_sort(int *data, size_t n) {
  for (size_t i = 1; i < n; ++i) {
    int x = data[i];
    size_t j = i;
    while (j > 0 && data[j - 1] > x) {
      data[j] = data[j - 1];
      j--;
    }
    data[j] = x;
  }
}
