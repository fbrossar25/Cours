struct list *list_remove_back(struct list *self) {
  if (self->next == NULL) {
    free(self);
    return NULL;
  }
  self->next = list_remove_back(self->next);
  return self;
}
