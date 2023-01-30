#include<stdio.h>
#define DIGITS 126
char buf[DIGITS+2]; /* ← 改行文字とナル文字の 2文字分だけ多く buf を用意 */


int main(){
  int i, len, len2;
  int arr[DIGITS] = {}; /* ←要素が全て 0 の配列を作るために {} と書く*/
  i = 0;
    
  fgets(buf,sizeof(buf),stdin); /* ←改行までの文字列を buf に格納 */
  while(buf[i]!='\n')++i; /* ←buf の改行の位置を探す (入力の長さがわかる) */
  len = i; /* ←改行の位置を len に保存 */
  for(i=0; i<len; ++i){
    arr[i] = (int)(buf[len-1-i]-'0');
  }

  i = 0;
  fgets(buf, sizeof(buf), stdin);
  while(buf[i] != '\n')i++;
  len2 = i;    /*2つ目の長さ*/
  if(len < len2){len = len2;   /*長いほうの文字数に合わせる*/
    for(i=0; i<len; i++){arr[i] = (int)(buf[len2-1-i]-'0') + arr[i];}
  }else{
    for(i=0; i<len2; i++){arr[i] = (int)(buf[len2-1-i]-'0') + arr[i];}
  }
    
  int count = 0;
  for(i=0; i<len; i++){  /*配列の中が10以上だった時の処理*/
    arr[i] = arr[i] + count;
    if(arr[i] < 10){    /*繰り上がりないなら桁上がり０にして次へ*/
      count = 0;
    }else{
      arr[i] = arr[i] - 10;
      count = 1;      
    }
  }

  if(count==1){
    if(len == 126){
      printf("1");
      for(i=len-1; i>=0; i--){printf("%d", arr[i]);}
    }else{
      arr[len] = arr[len] + count;
      for(i=len; i>=0; i--){printf("%d", arr[i]);}
    }
  }else{
    for(i=len-1; i>=0; i--){printf("%d", arr[i]);}
  }

  printf("\n");
  return 0;
}
