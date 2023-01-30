#include<stdio.h>
struct student { int id; char name[32]; int score; };

int main() {
  int i=0, n, v;
  char buf[128], c;
  struct student st[1024];
  while(fgets(buf,sizeof(buf),stdin)!=NULL&&i<1024) {
    sscanf(buf, "%d%c", &v, &c);
    if(c==',') {
      st[i].id = v;
      sscanf(buf, "%*d,%[^,],%d", st[i].name, &st[i].score);
      ++i;
    }
  }
  n = i;
  /* この時点で v に探索すべき得点が入っていて、n が読み込んだ要素の数である */
  st[n].score = v;
  i = 0;
  while(st[i].score != v){
    i++;
  }

  if(i==n){
    printf("Not found.");
  }else{
    printf("%d,%s\n", st[i].id, &st[i].name);
  }
  /* for 文や while 文において i<n のような添字による終了判定をしないこと */
  return 0;
}
