size_t list_size(const struct list *self) {
  if (self == NULL) {
    return 0;
  }
  return 1 + list_size(self->next);
}
