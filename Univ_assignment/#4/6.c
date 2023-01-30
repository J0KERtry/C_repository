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
  if(q->front ==  q->rear)return 1;
  else return 0;
}

elementtype getq(struct queue *p){
  elementtype m = p->contents[p->front];
  p->front++;
  return m;
}

void putq(struct queue *p, elementtype e){
  if(p->rear < MAXQUEUE){
    p->contents[p->rear] = e;
    p->rear++;
  }
}

int main(){
  struct queue s;
  int i, j;
  char buf[128];
  initqueue(&s);
  while(fgets(buf, sizeof(buf), stdin) != NULL) {
    if(buf[0] == 'g'){  /*getの指示をされた場合の動作*/
      if(queueempty(&s)){printf("Underflow\n");break;}
      else{getq(&s);}
    }else{              /*putの指示をされた場合の動作*/
      if(s.rear == MAXQUEUE){printf("Sorry\n");break;}
      else{sscanf(buf,"%d", &i); putq(&s, i);}
    }

    for(j = s.front; j < s.rear; j++){
      printf("[%d]", s.contents[j]);
    }
    printf("\n");
  }
}
