struct list *list_insert_back(struct list *self, int e) {
  if (self == NULL) {
    struct list *last = malloc(sizeof(struct list));
    last->data = e;
    last->next = NULL;
    return last;
  }
  self->next = list_insert_back(self->next, e);
  return self;
}
