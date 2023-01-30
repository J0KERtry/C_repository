#include<stdio.h>
#include<stdlib.h>
#define MAXSTACK 128 /* スタックの要素数の最大値 */
typedef int elementtype;
struct stack {
  int top; /* 最後に入れた要素の位置 (添字)、スタックが空なら -1 */
  elementtype contents[MAXSTACK]; /* 要素を含む配列。0番目からtop 番目までがスタックの要素　 */
};

void initstack(struct stack *p){
  int i;
  p->top = -1; 
  for(i=0; i<MAXSTACK; i++){
    p->contents[i] = 0;
  }
}

int stackempty(struct stack *p){
  if(p->top == -1){return 1;}
  else{return 0;}
}

elementtype pop(struct stack *p){
  elementtype num;
  if(!stackempty(p)){
    num = p->contents[p->top];
    p->top--;
    return num;
  }
}

void push(struct stack *p, elementtype e){
  if(p->top < MAXSTACK-1){
    p->top++;
    p->contents[p->top] = e;
  }
  return;
}

int main(){
  struct stack s;
  int i, j;
  char buf[128];
  initstack(&s);

  while(fgets(buf, sizeof(buf), stdin) != NULL) {
    if(buf[0] == 'p'){  /*ポップの指示をされた場合の動作*/
      if(stackempty(&s)){printf("Underflow\n"); exit(1);}
      else{pop(&s);}
    }else{              /*プッシュの指示をされた場合の動作*/
      if(s.top == MAXSTACK-1){printf("Overflow\n"); exit(1);}
      else{sscanf(buf,"%d", &i); push(&s, i);}
    }
    for(j = 0; j <= s.top; j++){
      printf("[%d]", s.contents[j]);
    }
    printf("\n");
  }
}
