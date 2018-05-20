void array_quick_sort_partial(int *data,
                                    ssize_t i, ssize_t j) {
  if (i < j) {
    ssize_t p = array_partition(data, i, j);
    array_quick_sort_partial(data, i, p - 1);
    array_quick_sort_partial(data, p + 1, j);
  }
}

void array_quick_sort(int *data, size_t n) {
  array_quick_sort_partial(data, 0, n - 1);
}
