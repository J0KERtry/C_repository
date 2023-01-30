#include<stdio.h>
#include<stdlib.h>
#define MAXQUEUE 128
typedef int elementtype;
struct queue{
  int front; int rear; elementtype contents[MAXQUEUE];
};

void initqueue(struct queue *p){
  int i;
  p->front = 0;
  p->rear = 0;
  for(i=0; i<MAXQUEUE; i++){
    p->contents[i] = 0;
  }
}

int queueempty(struct queue *q){
  if(q->front ==  q->rear)return 0;
  else return 1;
}

elementtype getq(struct queue *p){
  elementtype m;
  m = p->contents[p->front];
  if(p->front == MAXQUEUE-1){
    p->front = 0;
  }else{
    p->front++;
  }
  return m;
}

void putq(struct queue *p, elementtype e){
  p->contents[p->rear] = e;
  if(p->rear == MAXQUEUE-1){
    p->rear = 0;
  }else{
    p->rear++;
  }
}

int queuemax(struct queue *p){
  int flag = 0; /*0は空きあり*/
  if(p->front == 0 && p->rear == MAXQUEUE-1)flag++;
  else if(p->rear == p->front-1)flag++;
  return flag;
}

int main(){
  struct queue s;
  int i, j;
  char buf[128];
  initqueue(&s);

  while(fgets(buf, sizeof(buf), stdin) != NULL) {
    if(buf[0] == 'g'){  /*getの指示をされた場合の動作*/
      if(queueempty(&s) == 0){printf("Underflow\n"); break;}
      else{getq(&s);}
    }else{              /*putの指示をされた場合の動作*/
      if(queuemax(&s)){printf("Overflow\n"); break;}
      else{sscanf(buf,"%d", &i); putq(&s, i);}
    }

    for(j = s.front; j != s.rear; j++){
      printf("[%d]", s.contents[j]);
      if(j == MAXQUEUE-1){j = -1;}
    }
    printf("\n");
  }
}
