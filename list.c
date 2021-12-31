#include <stdlib.h>

#include "list.h"

struct link {
  void* val;
  struct link* next;
};

struct list {
  struct link* head;
};

struct list* list_create() {
  struct list* head = malloc(sizeof(struct list)); /* entire linked list */

  head->head = NULL;

  return head;
}

void list_free(struct list* list) {


  struct link* temp = list->head;
    struct link* prev ;
  while( temp != NULL){
    prev = temp->next;
    free(temp);
    temp = prev;
  }
  free(list);
  return;
}

void list_insert(struct list* list, void* val) {

  struct link* new_node = malloc(sizeof(struct link)); /* just one node */

  new_node->val = val;
  new_node->next = list->head;

  list->head = new_node;
  /* pushing it front */
  
  return;
}

void list_remove(struct list* list, void* val, int (*cmp)(void* a, void* b)) {

  struct link* temp = list->head; /* pointing it to the head of our list */
  struct link* prev;

  if (cmp(val, temp->val) == 0) {
        list->head = temp->next;
        free(temp); 
        return;
        }

  while (temp != NULL){

    if (cmp(val, temp->val) == 0) {
        prev->next = temp->next;
        free(temp); /* so that we are freeing the first val */
        break;
        }
        prev = temp;
        temp = temp->next; /* mooving towards the end of the list */
    }

  return;
}

int list_position(struct list* list, void* val, int (*cmp)(void* a, void* b)) {

  struct link* temp = list->head;
  int counter = 0;


  while (temp != NULL){
    if (cmp(val, temp->val) == 0) {
      return counter;
    }
    counter++;
    temp = temp->next;
  }

    return -1;
}

void list_reverse(struct list* list) {
  
  struct link* temp = list->head->next;
  struct link* prev = list->head;
  struct link* next = NULL;

  list->head->next = NULL;
  while (temp != NULL){
    next = temp->next;
    temp->next = prev;
    prev = temp;

    temp = next;
  }
  list->head = prev;
  return;
}

void* list_get_head(struct list* list) {
  struct link* temp = list->head;
  if (temp){
    return temp->val;
  }
  return NULL;
}

void* rem_head_get_val(struct list* list){
  struct link* temp = list->head; /* pointing it to the head of our list */
  /* struct link* prev;*/
  void* val = temp->val;

  list->head = temp->next;
  free(temp); 

  return val;
}

int check_if_empty(struct list* list){
  if (list->head == NULL){
    return 1;
  }
  return 0;
}