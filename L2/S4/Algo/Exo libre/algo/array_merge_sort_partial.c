void array_merge_sort_partial(int *data,
                            size_t i, size_t j, int *tmp) {
  if (j - i < 2) {
    return;
  }
  size_t m = (i + j) / 2;
  array_merge_sort_partial(data, i, m, tmp);
  array_merge_sort_partial(data, m, j, tmp);
  array_merge(data, i, m, j, tmp);
  memcpy(data, tmp + i, (j - i) * sizeof(int));
}
