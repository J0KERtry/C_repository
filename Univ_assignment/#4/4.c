#include<stdio.h>
#include<stdlib.h>
#define MAXSTACK 512
typedef int elementtype; 
struct stack{ 
  int top;
  elementtype contents[MAXSTACK];   
};

void initstack(struct stack *p){
  int i;
  p->top = -1;
  for(i=0; i < MAXSTACK; i++){
    p->contents[i] = 0;
  }
}

int stackempty(struct stack *p){
  if(p->top == -1){return 1;}
  else{return 0;}
}

elementtype pop(struct stack *p){
  elementtype result;
  if(!stackempty(p)){
    result = p->contents[p->top];
    p->top--;
    return result;
  }
}

void push(struct stack *p, int brackets){
  if(p->top < MAXSTACK-1){
    p->top++;
    p->contents[p->top] = brackets;
  }
}

int main(){
  int i; int flag = 0;
  struct stack s;
  char buf[2048];
  initstack(&s);
  fgets(buf, sizeof(buf), stdin);

  for(i=0; buf[i] != '\n'; i++){
        
    if(flag == 0 &&(buf[i] == '(' || buf[i] == '[' || buf[i] == '{' || buf[i] == '<')){
      push(&s, buf[i]);
    }else{
      switch(buf[i]){
      case ')': 
	if(pop(&s) != '('){flag = 1;}
	break;
      case ']': 
	if(pop(&s) != '['){flag = 1;}
	break;
      case '}' :
	if(pop(&s) != '{'){flag = 1;}
	break;
      case '>' :
	if(pop(&s) != '<'){flag = 1;}
	break;
      default: break;
      }
    } 
  }

  if(flag || !stackempty(&s)){printf("Bad");}
  else{printf("Good");}
}
