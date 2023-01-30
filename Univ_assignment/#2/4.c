#include <stdio.h>
#include <string.h>

int sosu(int n){
  int i;
  int flag = 0;                       //flag <- 素数判定
  if(n == 0 || n == 1) flag = 1;      //0と1は素数フラグ下す
  for(i = 2; i < n; i++){             
    if(n % i == 0) flag = 1;        //もしnが2以上の数で割れたら素数フラグ下す
  }
  return flag;
}

int main(void){
  int i;
  char str[1000];
  gets(str);
  for(i = 1; i <= strlen(str); i++){
    if(sosu(i) == 0){printf("%c", str[i-1]);}   //もし素数判定されれば、その番号－1の文字列表示
  }
}
