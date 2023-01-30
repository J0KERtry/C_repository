#include<stdio.h>
char kijun; /* 大小比較の規準を表すグローバル変数 */
struct point { int x, y; };

int compare(struct point p1, struct point p2) {
  int dist1, dist2;
  switch(kijun){
  case 'X':
    if(p1.x > p2.x)return 1;
    else if(p1.x < p2.x)return -1;
    else{
      if(p1.y > p2.y)return 1;
      else if(p1.y < p2.y)return -1;
      else return 0;
    }
    break;
  case 'Y':
    if(p1.y > p2.y){return 1;}
    else if(p1.y < p2.y){return -1;}
    else{
      if(p1.x > p2.x)return 1;
      else if(p1.x < p2.x)return -1;
      else return 0;
    }
    break;
  case 'D':
    dist1 = p1.x*p1.x + p1.y*p1.y;
    dist2 = p2.x*p2.x + p2.y*p2.y;
    if(dist1 > dist2){return 1;}
    else if(dist1 < dist2){return -1;}
    else{
      if(p1.x > p2.x)return 1;
      else if(p1.x < p2.x)return -1;
      else{
	if(p1.y > p2.y)return 1;
	else if(p1.y < p2.y)return -1;
	else return 0;
      }
    }
    break;
  }
}

int is_heap(struct point a[], int n) {
  int flag = 1;
  int i;
  for(i=1; i<n; i++){
    if(i%2 == 1){
      if(compare(a[i/2], a[i]) == -1)flag = 0;
    }else{
      if(compare(a[i/2 - 1], a[i]) == -1)flag = 0;
    }
  }
  return flag;
}

int main() {
  char buf[128];
  struct point p, arr[128];
  int i = 0, n;
  scanf("%c ",&kijun);
  while(fgets(buf,sizeof(buf),stdin)!=NULL && i<128) {
    sscanf(buf,"%d %d",&p.x,&p.y);
    arr[i] = p;
    ++i;
  }
  n = i;
  if (is_heap(arr, n)) printf("Yes.\n"); /* 関数 is_heap が 1 を返せば Yes.を出力 */
  else printf("No.\n"); /* 0 を返せば No.を出力 */
  return 0;
}
