void list_remove_after(struct list *self) {
  struct list *other = self->next;
  self->next = other->next;
  free(other);
}
