#include <stdio.h>
#include <stdlib.h>
typedef struct node *list;
typedef int elementtype;
struct node{
  elementtype element;
  struct node *next;
};

list cons(elementtype e, list l){
  list new = (list)malloc(sizeof(struct node));
  new->element = e;
  new->next = l;
  return new;
}

int length(list l){
  int count;
  list p = l->next;
  for(count=0; p; p=p->next, count++);
  return count;
}

void print_int_list(list l){
  while(l->next != NULL){
    printf("[%d]", l->next->element);
    l = l->next;
  }
}

int main(){
  int i;
  char buf[128];
  list l, last;
  l = (list)malloc(sizeof(struct node));
  l->next = NULL;
  last = l;
  while(fgets(buf,sizeof(buf),stdin) != NULL) {
    sscanf(buf,"%d",&i);
    last->next = cons(i, NULL);
    last = last->next;
  }
  printf("length=%d\n", length(l));
  print_int_list(l);
  free(l);
  return 0;
}
