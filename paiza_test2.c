#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_BUF_SIZE  1024

int main(void) {
  static char line[LINE_BUF_SIZE];
  // 縦、横の値を取得
  int H, W;  
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%d %d", &H, &W);  
  // 与えられた盤面を2次元配列に格納
  char grid[H][W];
  for(int i=0; i<H; i++){  
    for(int j=0; j<W; j++){
      scanf("%c", &grid[i][j]);
    }
    scanf("%*c");
  }
  // 答えの経路を取得
  char *ans;
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%s", ans);

  //****盤面全探索****//
  int count = 0; // 経路の数を格納
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(grid[i][j]==*ans){  // マスの文字と、答えの経路の1文字目が一致していたら
        char *p = ans;  // 作業用ポインタpを用意
        p++;
        int _i = i, _j = j;   // 作業用変数_i, _jを用意
        int len = 0; // 文字数格納用
        while(_j<W-1 && grid[_i][_j+1]==*p){  // 右端でない かつ 右のマスが答えの次の経路と等しいなら、右へ移動
          _j++; p++; len++;
        }
        while(_i<H-1 && grid[_i+1][_j]==*p){  // 下端でない かつ 下のマスが答えの次の経路と等しいなら、下へ移動
          _i++; p++; len++;
        }
        if(len==strlen(ans))count++;  // これまで通った経路長が答えと等しければcountを+1
      }
    }  
  }

  printf("%d\n", count);
  return 0;
}