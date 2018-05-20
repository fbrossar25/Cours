ssize_t array_partition(int *data, ssize_t i, ssize_t j) {
  ssize_t pivot_index = i;
  const int pivot = data[pivot_index];
  array_swap(data, pivot_index, j);
  ssize_t l = i;
  for (ssize_t k = i; k < j; ++k) {
    if (data[k] < pivot) {
      array_swap(data, k, l);
      l++;
    }
  }
  array_swap(data, l, j);
  return l;
}
