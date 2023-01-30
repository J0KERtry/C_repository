#include<stdio.h>
#include<stdlib.h>
char buf[256];

int main() {
  int i, j, ekisu;
  scanf("%d ", &ekisu);
  // 配列の初期化
  int adjmat[ekisu][ekisu];
  for(i=0; i<ekisu; i++){   
    for(j=0; j<ekisu; j++){
      adjmat[i][j] = 0;
    }
  }

  // 隣接する箇所を1にする
  while(fgets(buf,sizeof(buf),stdin)!=NULL) {
    sscanf(buf, "%d:%d ", &i, &j);
    adjmat[i][j] = 1;
    adjmat[j][i] = 1;
  }

  // 2次元配列の表示
  for(i=0; i<ekisu; i++){
    for(j=0; j<ekisu; j++){
      printf("%d", adjmat[i][j]);
    }
    printf("\n");
  }
  return 0;
}
