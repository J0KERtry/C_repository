#include<stdio.h>
#include<stdlib.h>
char buf[128]; /* 関数 get_tree で用いるグローバル変数 */
int count=0; /*関数size, sum用*/
typedef int datatype;
struct node { datatype data; struct node *left, *right; };

struct node* get_tree() {
  struct node *t;
  /* 標準入力から buf に文字列を読み込み、先頭が . なら葉とみなして NULL を返す */
  if(fgets(buf,sizeof(buf),stdin)==NULL || buf[0]=='.'){
    return NULL;
  } else {
    /* 先頭が . 以外なら、節点のためのメモリを確保 */
    t = (struct node*)malloc(sizeof(struct node));
    sscanf(buf,"%d ",&t->data); /* buf から数値として読み込み、メンバ data に保存 */
    t->left = get_tree(); /* 以降の入力で、左の子の節点から下の木を生成 */
    t->right = get_tree(); /* 左の木が生成できたら、右の子の節点から下の木を生成 */
    return t;
  }
}

int size(struct node *t) {
  if(t!=NULL){
    count++;
    size(t->left);
    size(t->right);
  }
  return count;
}

int height(struct node *t) {
  int rh, lh = 0;
  if(t==NULL)return 0;
  else{
    lh = height(t->left);
    rh = height(t->right);    
    if (lh > rh) return( lh+1 );
    else return( rh+1 );
  }
}

int sum(struct node *t) {
  int s = 0;
  if(t==NULL)return 0;
  else{
    s += t->data + sum(t->left) + sum(t->right);    
    return s;
  }    
}


int main() {
  struct node *t = get_tree();
  printf("%d\n",size(t));
  printf("%d\n",height(t));
  printf("%d\n",sum(t));
  return 0;
}
