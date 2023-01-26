#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000000000  // プレイヤの数の最大値：10の9乗乗
// お菓子、プレイヤの存在範囲: 0 ~ 15000

int main(void) {
  int N, M;
  char buf[MAX_SIZE];
  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d %d\n", &N, &M);
  int a[N], _a[N], L[M], R[M];
  fgets(buf, sizeof(buf), stdin);
  for (int i=0; i<N; i++) {
    sscanf(&buf[2*i], "%d ", &a[i]);
    _a[i] = 0;
  }
  for (int i=0; i<M; i++){
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d %d\n", &L[i], &R[i]);
  }

  int alt, flag, flag_2; // flag: お菓子の位置と同じ位置の人がいるか,  flag_2: お菓子を越したか
  for(int i=0; i<M; i++){
    for(int x=L[i]; x<=R[i]; ){
      flag = 0; flag_2 = 0;

  // 1人ずつ確認し,(お菓子と同じ位置でない && お菓子を越えてない&& 全員確認してない) ときfor文継続 
      for(int n=0; (!flag && !flag_2 && n<N) ; n++){  
        if(a[n]==x) {   // お菓子の位置と一致している人の場合
          while(a[n]==x){ _a[n]++;  n++; } // ポイント加算
          x++;          // お菓子の位置を更新
          flag = 1;     // フラグを立てる
        }
        else if(a[n] > x) {  // お菓子と一致している人がいなくてお菓子の位置を越した場合
          alt = n;           // alt: 越した人のインデックスを保存
          flag_2 = 1;        // フラグを立てる
        }
      }

      if(flag_2){  // お菓子と一致している人がいなかった場合、すべての人の位置をお菓子に近づける
        for(int m=0; m<N; m++){
          if(m < alt) a[m]++;
          else a[m]--;
        }
      }
    }
  } 

  for(int i=0; i<N; i++) printf("%d ", _a[i]);  // 各々のポイント出力
}


/* 入力
   3 2
   3 5 10
   6 8
   2 3
   実行結果：2 3 1  */