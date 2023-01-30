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
  l->next = new;
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

void print_int_list(list l, list p){
  printf("[%d]", l->element);
  l = l->next;
  while(l != p){
    printf("[%d]", l->element);
    l = l->next;
  }
}

int main(){
  int i, max;
  char buf[128];
  list l, p, start;

  /*リストの初期化*/
  l = (list)malloc(sizeof(struct node));
  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d", &i);
  l->element = i;
  l->next = l;
  p = l; start = l;
  max = i;

  /*2つ目以降のリスト*/
  while(fgets(buf,sizeof(buf),stdin) != NULL) {
    sscanf(buf,"%d",&i);
    l = cons(i, l);
    l->next = p;
    if(i >= max){max = i; start = l;}
  }
    
  p = start;
  print_int_list(start, p);
  free(l);
  return 0;
}
