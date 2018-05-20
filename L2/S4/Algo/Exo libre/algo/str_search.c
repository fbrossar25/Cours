const char *str_search(const char *h, const char *n) {
  size_t i = 0;
  while (h[i] != '\0') {
    size_t j = 0;
    while (n[j] && h[i + j] && n[j] == h[i + j]) {
      j++;
    }
    if (n[j] == '\0') {
      return h + i;
    }
    i++;
  }
  return NULL;
}
