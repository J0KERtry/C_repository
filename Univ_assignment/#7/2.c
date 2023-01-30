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

int max_index_by(struct point a[], int n, char c) {
  int count=0;
  int i;
  struct point p = a[0];
  struct point comp;
  for(i=0; i<n; i++){
    comp = a[i];
    switch(compare_by(p, comp, c)){
    case -1:
      p = comp; count = i;
      break;
    case 0:
      p = comp; count = i;
      break;
    defalt:
      break;
    }
  }
  return count;
}

int main() {
  char c, buf[128];
  struct point p, arr[128];
  int i = 0;
  scanf("%c ",&c);
  while(fgets(buf,sizeof(buf),stdin)!=NULL && i<128) {
    sscanf(buf,"%d %d",&p.x,&p.y);
    arr[i] = p;
    ++i;
  }
  printf("%d\n", max_index_by(arr, i, c));
  return 0;
}
