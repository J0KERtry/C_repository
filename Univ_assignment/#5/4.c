#include<stdio.h>
#include<stdlib.h>
typedef struct node* list;
typedef char elementtype;
struct node {
  elementtype element;
  struct node* next;
};

list cons(elementtype e, list last) {
  list new = (list)malloc(sizeof(list));
  new->element = e;
  new->next = NULL;
  if(last != NULL){last->next = new;}
  return new;
}

int length(list l){
  int count = 0;
  list p = l->next;
  while(p != NULL){
    count++;
    p = p->next;
  }
  return count;
}

void print_list(list l){
  list p;
  do{
    p=l;
    printf("%c", l->element);
    l = l->next;
  }while(p->next != NULL);
  printf("\n");
}

void insert(list l, elementtype e){
  list new = (list)malloc(sizeof(list));
  new->element = e;
  new->next = l->next;
  l->next = new;
  free(new);
}

void delete(list l){
  if(l->next != NULL){
    l->next = l->next->next;
  }
}

int main() {
  int i, j;
  char c, buf[128];
  list l, last; 
  l = NULL; last = NULL;
  fgets(buf,sizeof(buf),stdin); /* ←1行目をbufに読み込み */
  for(i=0; (c = buf[i])!='\n'; i++) { /*←1文字ずつ処理するfor文*/
    last = cons(c, last);
    if(l==NULL)l=last;
  }
  print_list(l); /*1行目表示*/

  while(fgets(buf,sizeof(buf),stdin) != NULL) { /*2行目以降の操作*/
    sscanf(buf,"%d", &i);
    last = l;

    if(i > length(last)){;}
    else if(i == 0){l = l->next;}
    else{for(j=0; j < i-1; j++){last = last->next;} delete(last);}

    print_list(l);
  }
}
