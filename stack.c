/*
 * Name: Artem Kolpakov
 * Email: kolpakoa@oregonstate.edu
 */

#include <stdlib.h>

#include "stack.h"
#include "list.h"


struct stack {
  struct list* list;
};


struct stack* stack_create() {
  struct stack* stack = malloc(sizeof(struct stack));
  stack->list = list_create();
  return stack;
}


void stack_free(struct stack* stack) {
  list_free(stack->list);
  free(stack);
  return;
}


int stack_isempty(struct stack* stack) {
  return check_if_empty(stack->list);
}


void stack_push(struct stack* stack, void* val) {
  list_insert(stack->list, val);
  return;
}

void* stack_top(struct stack* stack) {
  return list_get_head(stack->list);
}


void* stack_pop(struct stack* stack) {
  return rem_head_get_val(stack->list);
  /* we just remove the current head and update the pointer to the next element */
}
