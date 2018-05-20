size_t list_search(const struct list *self, int e) {
  if (self == NULL) {
    return 0;
  }
  if (self->data == e) {
    return 0;
  }
  return 1 + list_search(self->next, e);
}
