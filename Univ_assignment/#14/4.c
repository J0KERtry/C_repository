#include<stdio.h>
#include<stdlib.h>
char buf[256];

void warshall(int n, int adjmat[n][n], int result[n][n]) {
  int k, i, j;
  int reach[n+1][n][n];
  // 隣接しているか、自身を指しているときは reach=1
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      if(adjmat[i][j] || i==j)reach[0][i][j] = 1; 
      else reach[0][i][j] = 0;
    }
  }
  // i から j に到着
  for(k=0; k<n; k++){
    for(i=0; i<n; i++){
      for(j=0; j<n; j++){
                reach[k+1][i][j] = 
		  (reach[k][i][j] || (reach[k][i][k]&&reach[k][k][j]));
      }
    }
  }
  // 到達可能かどうかを result にコピー
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      result[i][j] = reach[n][i][j];
    }
  }
}

int main() {
  int i, j, ekisu;
  scanf("%d ", &ekisu);
  int adjmat[ekisu][ekisu], result[ekisu][ekisu];
  // adjmat,result の初期化
  for(i=0; i<ekisu; i++){   
    for(j=0; j<ekisu; j++){
      adjmat[i][j] = 0;
    }
  }
  // 隣接する箇所を1にする
  while(fgets(buf,sizeof(buf),stdin)!=NULL) {
    sscanf(buf, "%d:%d ", &i, &j);
    adjmat[i][j] = 1;  adjmat[j][i] = 1;
  }

  warshall(ekisu, adjmat, result);

  // result の表示
  for(i=0; i<ekisu; i++){
    for(j=0; j<ekisu; j++){
      printf("%d", result[i][j]);
    }
    printf("\n");
  }
  return 0;
}
