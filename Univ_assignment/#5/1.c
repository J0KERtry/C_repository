#include <stdio.h>
#include <stdlib.h>
typedef struct node *list;
typedef int elementtype;
struct node{
  elementtype element;
  struct node *next;
};

list cons(elementtype e, list l){
  list new = (list)malloc(sizeof(list));
  new->element = e;
  new->next = l;
  return new;
}

int length(list l){
  int count = 0;
  while(l != NULL){
    count++;
    l = l->next;
  }
  return count;
}

void print_int_list(list l){
  while(l != NULL){
    printf("[%d]", l->element);
    l = l->next;
  }
}

int main(){
  int i;
  char buf[128];
  list l = NULL;
  while(fgets(buf,sizeof(buf),stdin) != NULL) {
    sscanf(buf,"%d",&i);
    l = cons(i, l);
  }
  printf("length=%d\n", length(l));
  print_int_list(l);
  return 0;
}
