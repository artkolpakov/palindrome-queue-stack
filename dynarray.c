#include <stdlib.h>
#include <assert.h>

#include "dynarray.h"

struct dynarray {
  void** data;
  int size;
  int capacity;
  int start; 
  int back; 
};

#define DYNARRAY_INIT_CAPACITY 4

struct dynarray* dynarray_create() {
  struct dynarray* da = malloc(sizeof(struct dynarray));
  assert(da);

  da->data = malloc(DYNARRAY_INIT_CAPACITY * sizeof(void*));
  assert(da->data);
  da->size = 0;
  da->capacity = DYNARRAY_INIT_CAPACITY;
  da->start = 0;
  da->back = 0;
  return da;
}

void dynarray_free(struct dynarray* da) {
  assert(da);
  free(da->data);
  free(da);
}

int dynarray_size(struct dynarray* da) {
  assert(da);
  return da->size;
}


void _dynarray_resize(struct dynarray* da, int new_capacity) {
  assert(new_capacity > da->size);

  void** new_data = malloc(new_capacity * sizeof(void*));
  assert(new_data);

  for (int i = 0; i < da->size; i++) {
    new_data[i] = da->data[(da->start + i)%da->capacity];
  }
  da->start = 0;
  free(da->data);
  da->data = new_data;
  da->capacity = new_capacity;
}

void dynarray_insert(struct dynarray* da, void* val) {
  assert(da);
  if (da->size == da->capacity) {
    _dynarray_resize(da, 2 * da->capacity);
  }

  da->back = (da->start + da->size)%da->capacity;
  da->data[da->back] = val;
  da->size++;
    return; 
}

void* dynarray_remove(struct dynarray* da, int idx) {
  assert(da);
  void* data = da->data[da->start];

  da->start++;
  da->start %= da->capacity;

  da->size--;
  return data;
}

void* dynarray_get(struct dynarray* da, int idx) {
  assert(da);

  return da->data[idx];
}

void dynarray_set(struct dynarray* da, int idx, void* val) {
  assert(da);
  assert(idx < da->size && idx >= 0);

  da->data[idx] = val;
}

int get_start(struct dynarray* da){
  return da->start;
}

int get_back(struct dynarray* da){
  return da->back;
}