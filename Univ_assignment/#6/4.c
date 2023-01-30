#include<stdio.h>
#include<stdlib.h>
typedef struct node *list;
typedef int elementtype;
struct node{
  elementtype element;
  struct node *next;
};

void insert(elementtype d, list l){
  list new = (list)malloc(sizeof(list));
  new->element = d;
  new->next = l->next;
  l->next = new;
}

int main(){
  int d, x, i, j;
  char c;
  list l1 = (list)malloc(sizeof(struct node));
  list l2 = (list)malloc(sizeof(struct node));
  list l3 = (list)malloc(sizeof(struct node));
  l1->next = NULL; 
  l2->next = NULL;
  l3->next = NULL;

  while((c=getchar())!='\n') { /* ←読み込んだ数値を c に入れて、改行文字まで以下を繰り返す */
    d = (int) c - '0'; /* ← 読み込んだ数字を int 型として d に格納 */
    insert(d, l1);
  }
  while((c=getchar())!='\n') { /* ←読み込んだ数値を c に入れて、改行文字まで以下を繰り返す */
    d = (int) c - '0'; /* ← 読み込んだ数字を int 型として d に格納 */
    insert(d, l2);
  }    

  d=0;
  list l1_init = l1;   /* かけられる数の元の位置保存*/
  list l3_init = l3;     /* 計算結果の初期位置保存 */
  list l3_base = l3_init;
  for(j=0; l2->next!=NULL; l2=l2->next, j++){
    l1 = l1_init;  
    l3 = l3_base;
    for(i=0; l1->next!=NULL; l1=l1->next, i++){
      x = l1->next->element * l2->next->element;
      if(x!=0)d++;
      if(l3->next==NULL){insert(x, l3);}
      else{l3->next->element = l3->next->element + x;}
      l3 = l3->next;
    }
    if(l3_base->next==NULL){insert(0, l3_base);} 
    l3_base = l3_base->next; 
  }

  l3 = l3_init;
  int count = 0;
  while(l3->next!=NULL){
    l3->next->element = l3->next->element + count;
    if(l3->next->element < 10){
      count = 0;
    }else{
      count = l3->next->element;
      l3->next->element = l3->next->element % 10;
      count = (count - l3->next->element)/10;
    }
    l3 = l3->next;
  }
  if(count!=0){
    insert(0,l3);
    l3->next->element = l3->next->element + count;
  }

  l1 = l3_init; l3 = l3_init;
  if(d==0){printf("%d", d);}
  else{
    l1 = l3_init;
    while(l1!=NULL){l1 = l1->next;}
    while(1){
      l3 = l3_init;
      while(l3->next!=l1){l3 = l3->next;}
      l1 = l3;
      if(l3!=l3_init){printf("%d",l3->element);}
      else{break;}
    }
  }
  printf("\n");
  return 0;
}
