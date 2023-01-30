#include <stdio.h>
#define d 2718

int amari(int a, int b){
  int result = 1;
  if(b == 0){
    return result;      //0乗になったら終了
  }else if(b%2 == 0){
    result = (result * (amari(a, b/2)%d) * (amari(a, b/2)%d)) % d;  //指数が偶数の時の操作
  }else{
    result = (result * (amari(a, b-1) % d) * (a % d)) %d;           //指数が基数の時の操作
  }
  return result;
}

int main(void){
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d\n", amari(a, b));
}

