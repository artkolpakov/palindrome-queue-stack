#include <stdlib.h>

#include "queue.h"
#include "dynarray.h"

struct queue {
  struct dynarray* array;
};

struct queue* queue_create() {
  struct queue* queue = malloc(sizeof(struct queue));
  queue->array = dynarray_create();
  
  return queue;
}

void queue_free(struct queue* queue) {
  dynarray_free(queue->array);
  free(queue);
  return;
}

int queue_isempty(struct queue* queue) {
  if (dynarray_size(queue->array) == 0){
    return 1;
  }
  return 0;
}

void queue_enqueue(struct queue* queue, void* val) {
  dynarray_insert(queue->array, val);
  return;
}

void* queue_front(struct queue* queue) {
  return dynarray_get(queue->array, get_start(queue->array));
}

void* queue_dequeue(struct queue* queue) {
  return dynarray_remove(queue->array, get_start(queue->array));
}
