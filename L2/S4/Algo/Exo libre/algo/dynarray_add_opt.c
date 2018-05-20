void array_add(struct array *self, int e) {
  if (self->size == self->capacity) {
    self->capacity *= A;
    int *data = calloc(self->capacity, sizeof(int));
    memcpy(data, self->data, self->size * sizeof(int));
    free(self->data);
    self->data = data;
  }
  self->data[self->size] = e;
  self->size += 1;
}
