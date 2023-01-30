#include<stdio.h>
#include<stdlib.h>
typedef int elementtype;
struct dlnode{
  elementtype element;
  struct dlnode *prev, *next;
};

void insert(struct dlnode *p, elementtype e){
  struct dlnode *new = (struct dlnode*)malloc(sizeof(struct dlnode));
  new->element = e;
  new->prev = p->prev; p->prev->next = new; p->prev = new; new->next = p;
}

void delete(struct dlnode *p){
  p->prev->next = p->next;
  p->next->prev = p->prev;
  free(p); 
}

void print_dllist(struct dlnode *d){
  struct dlnode *mark = d;
  if(d->next != d){
    do{
      d = d->next;
      printf("[%d]", d->element);
    }while(d->next != mark);
    d = mark;
    do{
      d = d->prev;
      printf("{%d}", d->element);
    }while(d->prev != mark);
  }
  printf("\n");
}

void append_dllist(struct dlnode *d1, struct dlnode *d2){
  d1->prev->next = d2->next;
  d2->next->prev = d1->prev;
  d2->prev->next = d1;
  d1->prev = d2->prev;
  free(d2);
}

int main() {
  char buf[128];
  int i;
  struct dlnode *d1, *d2, *mark;
  /* ※ここでd1、d2が空の双方向リストのダミーの節点を指すように初期化*/
  d1 = (struct dlnode*)malloc(sizeof(struct dlnode));
  d2 = (struct dlnode*)malloc(sizeof(struct dlnode));
  d1->prev = d1; d1->next = d1;
  d2->prev = d2; d2->next = d2;
  while(fgets(buf,sizeof(buf),stdin)!=NULL){
    sscanf(buf,"%d",&i);
    insert(d1, i); /* ← d1 の末尾に i を要素として挿入 */
    insert(d2, i); /* ← d2 の末尾に i を要素として挿入 */
  }
  print_dllist(d1); /* ← d1 の内容を出力 */
  print_dllist(d2); /* ← d2 の内容を出力 */



  /* ※ここでdelete 関数を繰り返し用いて、d1 に含まれる奇数要素を削除 */
  mark = d1;
  while(mark->next != d1){
    if( (mark->next->element)%2 == 1 || (mark->next->element)%2 == -1){delete(mark->next);}
    else{mark = mark->next;}
  }
  /*※ここでdelete 関数を繰り返し用いて、d2 に含まれる偶数要素を削除 */
  mark = d2;
  while(mark->next != d2){
    if( (mark->next->element)%2 == 0){delete(mark->next);}
    else{mark = mark->next;}
  }
  print_dllist(d1); /* ← d1 の内容を出力 */
  print_dllist(d2); /* ← d2 の内容を出力 */

  append_dllist(d1,d2); /* ← d1 の末尾に d2 を連結 */
  print_dllist(d1); /* ← d1 の内容を出力 */
  free(d1); free(d2);
  return 0;
}
