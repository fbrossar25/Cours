void list_insert_after(struct list *self, int e) {
  struct list *other = malloc(sizeof(struct list));
  other->data = e;
  other->next = self->next;
  self->next = other;
}
