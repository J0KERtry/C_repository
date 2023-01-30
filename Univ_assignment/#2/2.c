#include <stdio.h>

int combination(int n, int k){
  int i, j;
  int r[1000][1000] = {1};            //二次元配列を1に設定
  for(i = 0; i <= n; i++){                
    for(j = 0; j <= i; j++){
      if(j == 0 || i == j){r[i][j] = 1;}      
      else{r[i][j] = (r[i-1][j] + r[i-1][j-1]) % 2718;} 
    }
  }
  return r[n][k];
}

int main(void){
  int n, k;
  scanf("%d %d", &n, &k);
  printf("%d\n",combination(n, k));
}
