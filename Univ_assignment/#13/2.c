#include<stdio.h>
#include<stdlib.h>
char buf[128];

struct student { int id; char name[32]; int score; };
typedef struct student datatype; /* ← 格納するデータは構造体 student */
struct rb_node { datatype data; struct rb_node *left, *right; int black; };

struct rb_node* get_rbtree() {
  struct rb_node *t;
  char c;
  /* ドットだけなら葉 (NULL) を返す */
  if(fgets(buf,sizeof(buf),stdin)==NULL || buf[0]=='.')
    return NULL;
  else {
    /* ドットでなければ節点を表す構造体のアドレス t を用意 */
    t = (struct rb_node*)malloc(sizeof(struct rb_node));
    /* 色を表す文字を c に、学籍番号、名前、得点を t->data に格納 */
    sscanf(buf,"[%c]%d,%[^,],%d",&c,&t->data.id,t->data.name,&t->data.score);
    /* 色の文字が b なら 1、r なら 0 */
    t->black = (c=='b');
    /* 左の子を t->left に、右の子を t->right に格納 */
    t->left = get_rbtree(); t->right = get_rbtree();
    /* t を返す */
    return t;
  }
}

int is_red(struct rb_node *t){
  return (t != NULL && !t->black);
}

int is_rbtree(struct rb_node *t) {
  int l, r, equal;
  if(t==NULL)return 1;
  else if(is_red(t)){ /*ノードが赤のとき*/
    if(is_red(t->left) || is_red(t->right)) return 0;   /*どちらかの子も赤*/
  }

  l = is_rbtree(t->left); 
  if(l==0)return 0;
  r = is_rbtree(t->right);
  if(r==0)return 0;
    
  if(l!=r)return 0;
  equal = l;
  if(t->black==1)equal++;
  return equal;
}

int main() {
  struct rb_node *t = get_rbtree();
  if(is_rbtree(t)) printf("Yes.\n");
  else printf("No.\n");
  return 0;
}
