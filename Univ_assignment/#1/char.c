#include <stdio.h>

int main(void){
  char str[128];
  fgets(str, 128, stdin);
  printf("%s", str);
}
