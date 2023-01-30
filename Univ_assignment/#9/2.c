#include<stdio.h>
int count = 0;
char kijun; /* 大小比較の規準を表すグローバル変数 */
struct point { int x, y; };

int compare(struct point p1, struct point p2) {
  count++;
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

void pushdown(struct point a[], int m, int n) {
  int i;
  struct point alt;
  if(2*m+2 <= n){
    if(compare(a[2*m+1], a[2*m+2]) == 1){i = 2*m+1;}
    else{i = 2*m+2;}
    if(compare(a[i], a[m]) == 1){
      alt = a[i];
      a[i] = a[m];
      a[m] = alt;
      pushdown(a, i, n);
    }
  }else if(2*m+1 == n){
    if(compare(a[2*m+1], a[m]) == 1){
      alt = a[2*m+1];
      a[2*m+1] = a[m];
      a[m] = alt;
    }
  }
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
  pushdown(arr, 0, n-1);
  printf("%d\n", count);
  for(i=0;i<n;++i)
    printf("%d %d\n", arr[i].x, arr[i].y);
  return 0;
}
