#include <stdio.h>

int main(void){
  int x, y, r;
  scanf("%d %d", &x, &y);
  if(x < y){r = x; x = y; y = r;}
  do{
    r = x % y;
    if(r == 0){
      printf("%d", y);
    }else{
      x = y; y = r;
    }
  }while(r != 0);
}
  
    
