#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

#include "queue.h"
#include "stack.h"

#define MAX_STR_LEN 256

int get_user_str(char* dest, int n) {
  printf("\nEnter a string, and we'll check whether it's a palindrome:\n");
  if (fgets(dest, MAX_STR_LEN, stdin) != NULL) {
    dest[strcspn(dest, "\r\n")] = '\0';
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char const *argv[]) {
  char* in = malloc(MAX_STR_LEN * sizeof(char));
  int flag = 1;

  while (get_user_str(in, MAX_STR_LEN)) {
    /*
    1) lower, get rid of spaces
    2) put each character in my queue at the stack and the queue
    3) take from the top of the stack and from the front of the queue and compare every
     single elemnt until we find one that does not match 
    */
  struct stack* my_stack = stack_create();
  struct queue* my_queue = queue_create();
  
  int length = strlen(in);
  int length_copy = length;

  for (int a =0; a< length; a++){
      in[a] = tolower(in[a]);
  }

  for (int i=0; i<length ; i++){
    if( isalpha(in[i]) != 0){
      queue_enqueue(my_queue, &in[i]);
      stack_push(my_stack, &in[i]);
    }
    else{
      length_copy--;
    }
  }

  for (int j = 0; j< length_copy; j++){
    char* popped;
    char* queued;

    popped = stack_pop(my_stack);
    queued = queue_dequeue(my_queue);

    if ( *popped != *queued ){
      flag = 0;
      break; 
    }
  }

  queue_free(my_queue);
  stack_free(my_stack);

  if (flag == 1){
    printf("that's a palindrome ! \n");
    break;
  }
  else{
    printf("that's not a palindrome ! \n");
    flag = 1;
  }
  }

  free(in);
  return 0;
}
