#include<stdio.h>
#define SETMAX 10600 /* 集合の要素数の最大値 (駅の数) */
char buf[256]; /* 入力された文字列を格納するグローバル変数 */

struct set { int elements[SETMAX]; int size; };

int delete_min_int(struct set *p) {
  int i, min, min_num;
  if(p->size==0) return -1;
  else{
    min = p->elements[0];   // 最小値を要素の一番最初にセット
    min_num = 0;    //  最小値の入った要素番号
    for(i=1; i<p->size; i++){
      if(min > p->elements[i]){
	min = p->elements[i];   // 最小値更新
	min_num = i;    // 要素番号更新
      }
    }
  }
  p->elements[min_num] = p->elements[p->size-1];
  p->size--;
  return min;
}

void print_set(struct set *p) {
  int i;
  printf("{");
  for(i=0;i<p->size;++i) printf(" %d",p->elements[i]);
  printf(" }\n");
}

int main() {
  struct set s; /* 入力される整数値を格納する集合 */
  int i, m;
  i = 0; /* 添字 0 から格納していく */
  while(fgets(buf,sizeof(buf),stdin)!=NULL) {
    sscanf(buf, "%d ", &s.elements[i]); /* 入力された整数値を集合 s に格納 */
    ++i; /* 添字を 1 つ増やす */
  }
  s.size = i; /* ← この時点で i に要素の数が格納されているはず */
  while(1) {
    m = delete_min_int(&s);
    if(m<0) break; /* m が負なら集合が空なので終了 */
    printf("%d : ",m); print_set(&s); /* 最小値と集合を出力 */
  }
  return 0;
}
