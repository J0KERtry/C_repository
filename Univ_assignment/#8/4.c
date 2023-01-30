#include<stdio.h>
int count = 0;
char kijun;
struct point { int x, y; };

int compare(struct point p1, struct point p2) {
  ++count;
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

void merge(struct point a[], int m, int n, int h) {
  int i;
  struct point sub[128];
  for(i = m; i <= n; i++){ sub[i] = a[i]; } // 配列a をsubにコピー

  int p1 = m;
  int p2 = h+1;
  i = m;
  while(i<=n){
    if(p2 == n+1 || (p1<=h && compare(sub[p1], sub[p2])<=0)){
      a[i] = sub[p1];
      p1++;
    }else{
      a[i] = sub[p2];
      p2++;
    }
    i++;
  }
}

void merge_sort(struct point a[], int m, int n) {
  if(m < n){
    int h = (m+n)/2;
    merge_sort(a, m, h);
    merge_sort(a, h+1, n);
    merge(a, m, n, h);
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
  merge_sort(arr, 0, n-1);
  printf("%d\n", count);
  for(i=0;i<n;++i)
    printf("%d %d\n", arr[i].x, arr[i].y);
  return 0;
}
