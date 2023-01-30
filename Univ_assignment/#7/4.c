#include<stdio.h>
struct point { int x, y; };

int compare_by(struct point p1, struct point p2, char c) {
  int result = 0;
  int dist1, dist2;
  switch(c){
  case 'X':
    if(p1.x > p2.x){return 1;}
    else if(p1.x < p2.x){return -1;}
    else{compare_by(p1, p2, 'Y');}
    break;
  case 'Y':
    if(p1.y > p2.y){return 1;}
    else if(p1.y < p2.y){return -1;}
    else if(p1.x==p2.x && p1.y==p2.y){return 0;}
    else{compare_by(p1, p2, 'X');}
    break;
  case 'D':
    dist1 = p1.x*p1.x + p1.y*p1.y;
    dist2 = p2.x*p2.x + p2.y*p2.y;
    if(dist1 > dist2){return 1;}
    else if(dist1 < dist2){return -1;}
    else{compare_by(p1, p2, 'X');}
    break;
  }
}

void insert_by(struct point a[], int n, char c) {
  struct point p = a[n-1];
  int i;
  for(i=n-1; i>0; i--){
    if(compare_by(p, a[i-1], c)==-1){
      a[i] = a[i-1];
    }else{
      a[i] = p;
      break;
    }
  }
  if(i==0){a[0]=p;}
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
  insert_by(arr, n, c);
  for(i=0;i<n;++i)
    printf("%d %d\n", arr[i].x, arr[i].y);
  return 0;
}
