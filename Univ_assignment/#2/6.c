#include <stdio.h>
#include <string.h>

int main(void){
  char *p; char str[1000];
  fgets(str, 128, stdin);
  if((p = strstr(str, "//")) != NULL){*p = '\0';}
  if((p = strstr(str, "\n")) != NULL){*p = '\0';}
  printf("%d\n", strlen(str));
}
