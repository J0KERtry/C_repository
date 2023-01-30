#include<stdio.h>

int max_index(int a[], int n){
  int i = 0;  //最大値の番号
  int max = a[0];  //初期最大値  
  for(int k=0; k<n; k++){
    if(a[k] >= max){max = a[k]; i = k;}
  }
  return i;
}

int main(){
  char buf[128];
  int arr[128], i = 0;
  while(fgets(buf,sizeof(buf),stdin)!=NULL && i<128)
    sscanf(buf,"%d",&arr[i++]);
  printf("%d\n", max_index(arr, i));
  return 0;
}
