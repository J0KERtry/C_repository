#include<stdio.h>
char buf[128];

/* p が指すアドレスにある整数に i を加算 */
void update(int *p, int i) {
  int alt = *p + i;
  if(alt <= -100 || alt >= 100){*p = 0;}
  else{*p = alt;}
  return;
}

/* main 関数の定義内は変更してはいけない */
int main() {
  int x = 0, i;
  while(fgets(buf, sizeof(buf), stdin) != NULL) {
    sscanf(buf, "%d", &i);
    update(&x, i);
    printf("%d\n", x);
  }
  return 0;
}
