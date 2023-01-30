#include<stdio.h>
#include<stdlib.h>
typedef int elementtype;
typedef struct node *list;
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

int main() {
  int d, x, y, count;
  count = 0;
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

  while(l1->next!=NULL || l2->next!=NULL){
    if(l1->next==NULL&&l2->next!=NULL){x=0; l2 = l2->next; y = l2->element;}
    else if(l2->next==NULL&&l1->next!=NULL){y=0; l1 = l1->next; x = l1->element; }
    else{
      l1 = l1->next; x = l1->element;
      l2 = l2->next; y = l2->element;
    }
    insert((x+y+count)%10, l3);
    if(x+y+count >= 10){count=1;}
    else{count = 0;}
  }
  if(count==1){insert(count, l3);}


  while(l3->next != NULL){
    printf("%d", l3->next->element);
    l3 = l3->next;
  }

  return 0;
}
