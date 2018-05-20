int *list_access(const struct list *self, size_t j) {
  if (self == NULL) {
    return NULL;
  }
  if (j == 0) {
    return &self->data;
  }
  return list_access(self->next, j - 1);
}
