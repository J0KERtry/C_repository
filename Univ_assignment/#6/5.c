#include<stdio.h>
#include<stdlib.h>
typedef struct node *list;
typedef int elementtype;
struct node{
  elementtype element;
  struct node *next;
};

void insert(elementtype d, list l){
  list new = (list)malloc(sizeof(struct node));
  new->element = d;
  new->next = l->next;
  l->next = new;
}

int main(){
  int d, x, i, j, time, move;
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
  for(j=0; l2->next!=NULL; l2=l2->next, j++){
    l1 = l1_init;
    for(i=0; l1->next!=NULL; l1=l1->next, i++){
      int pow = 1;
      for(time=0; time<(i+j)%4; time++){ pow = pow * 10;} /*累乗*/
      x = l1->next->element * l2->next->element * pow; 
      if(x!=0)d=1;    /* 0の存在判定 */
            
      if(i==0 && j==0){ 
	insert(0, l3);
      }else{
	l3 = l3_init; move = 0;
	while(move < (i+j)/4 && l3->next!=NULL){l3 = l3->next; move++;}
	if(l3->next==NULL){insert(0, l3);}
      }
      l3->next->element = l3->next->element + x;
    }
  }

  struct node *l_head, *l_prev;
  l3 = l3_init;
  //l_head = l3;  1回目は必要、2回目はl3_initが末尾なのでしない。
  l_prev = NULL;
  int count = 0;
  while(l3->next!=NULL){      /* 繰り上がり計算 */
    l3->next->element = l3->next->element + count;
    if(l3->next->element < 10000){
      count = 0;
    }else{
      count = l3->next->element;
      l3->next->element = l3->next->element % 10000;
      count = (count - l3->next->element)/10000;
    }
    l_head = l3;
    l3 = l3->next;
    l_head->next = l_prev; // 現在の次のノードを前のノードに
    l_prev = l_head; // 前のノードを現在のノードに
  }
  l3->next = l_prev;
  l_head = l3; // 現在のリストの先頭をl_headへ


  if(d==0){printf("%d", d);}
  else{
    if(count!=0){printf("%d", count);}
    else{printf("%d",l_head->element); l_head = l_head->next;}   /* 先頭表示 */
    while(1){
      if(l_head!=l3_init){printf("%04d",l_head->element);} /*4桁表示*/
      else{break;}
      l_head = l_head->next;
    }
  }
  printf("\n");
  return 0;
}
