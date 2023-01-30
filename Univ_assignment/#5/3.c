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
}


int main() {
  int i, j;
  char c, buf[128];
  list l = (list)malloc(sizeof(struct node));
  list last = l;

  fgets(buf,sizeof(buf),stdin); /* ←1行目をbufに読み込み */
  for(i=0; (c = buf[i])!='\n'; i++){ /*←1文字ずつ処理するfor文*/
    last = cons(c, last);
  }
  print_list(l); /*1行目表示*/

  while(fgets(buf,sizeof(buf),stdin) != NULL) { /*2行目以降*/
    sscanf(buf,"%d %c", &i, &c);    /*追加番号と文字読み取り*/
    last = l;                       /*last更新*/
    if(i > length(last)){i = length(last);}{
      for(j=0; j < i; j++){last = last->next;}
    }
    insert(last, c);
    print_list(l);
  }
  free(l);
}
