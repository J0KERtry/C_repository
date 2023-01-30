 #include<stdio.h>
#define SETMAX 10600 /* 集合の要素数の最大値 (駅の数) */

struct set { int elements[SETMAX]; int size; };

void init_set(struct set *p, int n, int e) {
  int i, j = 0;
  p->size = n-1;

  for(i=0; i<=p->size; i++){
    if(i!=e){
      p->elements[j] = i;
      j++;
    }
  }
}

void print_set(struct set *p) {
  int i;
  printf("{");
  for(i=0;i<p->size;++i) printf(" %d",p->elements[i]);
  printf(" }\n");
}

int main() {
  int n, e;
  struct set s; /* 集合 s を用意 */
  scanf("%d %d ", &n, &e); /* 入力から n と e を読み込み */
  init_set(&s, n, e); /* s のアドレスと n と e を渡す */
  print_set(&s);
  return 0;
}
