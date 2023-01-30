#include<stdio.h>
#include<stdlib.h>
char buf[128]; /* 関数 get_tree で用いるグローバル変数 */
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
 
void print_tree(struct node *t) {
  if(t==NULL){printf("-");}
  else{
    printf("%d(", t->data);
    print_tree(t->left);
    printf(",");
    print_tree(t->right);
    printf(")");
  }
}
 
int main() {
  struct node *t = get_tree();
  print_tree(t);
  printf("\n");
  return 0;
}
