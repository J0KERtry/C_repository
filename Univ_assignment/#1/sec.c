#include <stdio.h>

int main(void){
  int i, j, v;
  int flag = 0;
  int ten[10];
  for(i=0; i<10; i++){
    scanf("%d", &ten[i]);
  }

  for(i = 0; i < 10; i++){
    for(j = i; j < 10; j++){
      if(ten[j] < ten[i]){v = ten[i]; ten[i] = ten[j]; ten[j] = v;}
    }
  }
  printf("%d", ten[1]);
}
    
  
