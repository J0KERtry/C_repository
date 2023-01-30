#include<stdio.h>
int count = 0;
struct point { int x, y; };

int compare_by(struct point p1, struct point p2, char c) {
  ++count;
  int dist1, dist2;
  switch(c){
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

void bubble_sort(struct point a[], int n, char c){
  int k, l;
  struct point p;
  for(k=n-2; k>=0; k--){
    for(l=0; l<=k; l++){
      if(compare_by(a[l], a[l+1], c)==1){
	p = a[l]; a[l] = a[l+1]; a[l+1] = p;
      }
    }
  }
}


int main() {
  char c, buf[128];
  struct point p, arr[128];
  int i = 0, n;
  scanf("%c ",&c);
  while(fgets(buf,sizeof(buf),stdin)!=NULL && i<128) {
    sscanf(buf,"%d %d",&p.x,&p.y);
    arr[i] = p;
    ++i;
  }
  n = i;
  bubble_sort(arr, n, c);
  printf("%d\n", count);
  for(i=0; i<n; ++i)
    printf("%d %d\n", arr[i].x, arr[i].y);
  return 0;
}
