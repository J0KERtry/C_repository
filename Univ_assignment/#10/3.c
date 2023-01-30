#include<stdio.h>
#define SIZE 101

int hash(char *s) {
  int result = (int)*s % SIZE;
  s++;
  for(; *s!='\0'; s++){
    result = (result*128 + (int)*s) % SIZE;
  }
  return result;
}

int main() {
  char s[32];
  scanf("%[^\n]", s);
  printf("%d\n", hash(s));
  return 0;
}
