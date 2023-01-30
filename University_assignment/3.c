#include<stdio.h>
#define SETMAX 10600
char buf[256]; /* 入力された文字列を格納するグローバル変数 */
/* 最小要素を見つけるために利用される配列変数 dist (40 のあとの要素はすべて 0) */
int dist[SETMAX] = { 81, 52, 46, 80, 31, 67, 56, 31, 38, 40 };

struct set { int elements[SETMAX]; int size; };

int delete_min(struct set *p) {
  int i, min, min_num, store;
  if(p->size==0)return -1;
  else{
    min = dist[p->elements[0]]; 
    min_num = 0;
    for(i=1; i<p->size; i++){
      if(min > dist[p->elements[i]]){
	min = dist[p->elements[i]]; 
	min_num = i;
      }
    }
  }
  store = p->elements[min_num];
  p->elements[min_num] = p->elements[p->size-1];
  p->size--;
  return store;
}

void print_set(struct set *p) {
  int i;
  printf("{");
  for(i=0;i<p->size;++i) printf(" %d",p->elements[i]);
  printf(" }\n");
}

int main() {
  int i, m;
  struct set s; /* 入力される整数値を格納する集合 */
  i = 0; /* 添字 0 から格納していく */
  while(fgets(buf,sizeof(buf),stdin)!=NULL) {
    sscanf(buf, "%d␣", &s.elements[i]); /* 入力された整数値を集合 s に格納 */
    ++i; /* 添字を 1 つ増やす */
  }
  /* この時点で i に要素の数が格納されているはず */
  s.size = i;
  while(1) {
    m = delete_min(&s);
    if(m<0) break; /* m が負なら集合が空なので終了 */
    printf("%d : ",m); /* 見つけた最小要素を出力 */
    print_set(&s);
  }
  return 0;
}
