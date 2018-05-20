void array_merge_sort(int *data, size_t n) {
  int *tmp = calloc(n, sizeof(int));
  array_merge_sort_partial(data, 0, n, tmp);
  free(tmp);
}
