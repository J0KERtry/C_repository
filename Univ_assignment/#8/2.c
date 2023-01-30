#include <stdio.h>
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

int partition(struct point a[], int m, int n) {
  struct point pivot = a[m];
  int l = m+1;   
  int r = n;
  while(1){
    while(l < n && compare(pivot, a[l])==1){
      ++l;
    }
    while(m < r && compare(a[r], pivot)==1){
      --r;
    }
    if(l < r){
      struct point k;
      k = a[l];
      a[l] = a[r];
      a[r] = k;
    }else{break;}
    l++; r--;
  }

  struct point sub = a[m];
  a[m] = a[r];    
  a[r] = sub;
  return r;
}

void quicksort(struct point a[], int m, int n) {
  if(m < n){
    int p = partition(a, m, n);
    quicksort(a, m, p-1);
    quicksort(a, p+1, n);
  }
}

int main(){
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
  quicksort(arr, 0, n-1);
  printf("%d\n", count);
  for(i=0;i<n;++i)
    printf("%d %d\n", arr[i].x, arr[i].y);
  return 0;
}
