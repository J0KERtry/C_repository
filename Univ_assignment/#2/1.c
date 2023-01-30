#include <stdio.h>
#define d 2718
#define SIZE_of_arr 100000

int main(void){
  int i, n, fib[SIZE_of_arr] = {0, 1};               //初期値登録
  scanf("%d", &n);
  for(i = 2; i < SIZE_of_arr; i++){                  
    fib[i] = (fib[i-1] + fib[i-2]) %d;   //前の2つを足してdで割ったものを配列に入れる
  }
  printf("%d\n", fib[n]);
}
