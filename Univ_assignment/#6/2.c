#include<stdio.h>
#include<math.h>
#define DIGITS 126
char buf[DIGITS+2]; /* ← 改行文字とナル文字の 2文字分だけ多く buf を用意 */

int main(){
  int i, j, len, len2;
  int arr1[DIGITS] = {}; /* ←要素が全て 0 の配列を作るために {} と書く*/
  int arr2[DIGITS] = {};
  int out[DIGITS*2] = {};
  i = 0;
    
  fgets(buf,sizeof(buf),stdin); /* ←改行までの文字列を buf に格納 */
  while(buf[i]!='\n')++i; /* ←buf の改行の位置を探す (入力の長さがわかる) */
  len = i; /* ←改行の位置を len に保存 */
  for(i=0; i<len; ++i){
    arr1[i] = (int)(buf[len-1-i]-'0');
  }

  fgets(buf,sizeof(buf),stdin); /* ←改行までの文字列を buf に格納 */
  i=0;
  while(buf[i]!='\n')++i; /* ←buf の改行の位置を探す (入力の長さがわかる) */
  len2 = i; /* ←改行の位置を len に保存 */
  for(i=0; i<len2; ++i){
    arr2[i] = (int)(buf[len2-1-i]-'0');
  }    
    
  for(j=0; j<len2; j++){
    for(i=0; i<len; i++){
      out[i+j] = out[i+j] + (arr1[i] * arr2[j]);
    }
  }                          

  int count = 0;
  for(i=0; i<=len+len2; i++){  /*配列の中が10以上だった時の処理*/
    out[i] = out[i] + count;
    if(out[i] < 10){    /*繰り上がりないなら桁上がり0にして次へ*/
      count = 0;
    }else{              /*要素が10以上だった時*/
      count = out[i];
      out[i] = out[i] % 10;
      count = (count - out[i]) / 10;
    }
  }


  i = len + len2 - 1;
  while(out[i]==0 && i>0)i--;
  for(; i>=0; i--){
    printf("%d", out[i]);
  }
        

  printf("\n");
  return 0;
}
