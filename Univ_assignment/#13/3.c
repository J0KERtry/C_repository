#include<stdio.h>
#include<stdlib.h>
char buf[128];

struct student { int id; char name[32]; int score; };
typedef struct student datatype; /* ← 格納するデータは構造体 student */
struct rb_node { datatype data; struct rb_node *left, *right; int black; };

int is_red(struct rb_node *t){
  return (t != NULL && !t->black);
}

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

void print_rbtree(struct rb_node *t) {
  if(t==NULL) printf(".\n");
  else {
    printf("[%c]%d,%s,%d\n",t->black?'b':'r',t->data.id,t->data.name,t->data.score);
    print_rbtree(t->left); print_rbtree(t->right);
  }
}

struct rb_node* rotate_right(struct rb_node *t) {
  if(t->left == NULL)return t;
  else{
    struct rb_node *p;
    p = t->left;
    t->left = p->right;
    p->right = t;
    return p;
  }
}

struct rb_node* rotate_left(struct rb_node *t) {
  if(t->right == NULL)return t;
  else{
    struct rb_node *p;
    p = t->right;
    t->right = p->left;
    p->left = t;
    return p;
  }
}

struct rb_node* resolve_red_pair(struct rb_node *t) {
  /*Case 1*/
  if(is_red(t->left) && is_red(t->left->left)){
    /*Case 1.1*/    
    if(is_red(t->right)){
      t->black=0; t->left->black=1; t->right->black=1;
    }
    /*Case 1.2*/
    else{
      t = rotate_right(t);
      t->black=1; t->right->black=0;
    }
    t->left = resolve_red_pair(t->left); 
    t->right = resolve_red_pair(t->right);
  }

  /*Case 2*/
  else if(is_red(t->left) && is_red(t->left->right)){
    /*Case 2.1*/
    if(is_red(t->right)){
      t->black=0; t->left->black=1; t->right->black=1;
    }
    /*Case 2.2*/
    else{
      t->left = rotate_left(t->left);
      t = rotate_right(t);
      t->black=1; t->right->black=0;
    }
    t->left = resolve_red_pair(t->left); 
    t->right = resolve_red_pair(t->right);
  }

  /*Case 3*/
  else if(is_red(t->right) && is_red(t->right->left)){
    /*Case 3.1*/
    if(is_red(t->left)){
      t->black=0; t->right->black=1; t->left->black=1;
    }
    /*Case 3.2*/
    else{
      t->right = rotate_right(t->right);
      t = rotate_left(t);
      t->black=1; t->left->black=0;
    }
    t->left = resolve_red_pair(t->left); 
    t->right = resolve_red_pair(t->right);
  }

  /*Case 4*/
  else if(is_red(t->right) && is_red(t->right->right)){
    /*Case 4.1*/    
    if(is_red(t->left)){
      t->black=0; t->right->black=1; t->right->black=1;
    }
    /*Case 4.2*/
    else{
      t = rotate_left(t);
      t->black=1; t->left->black=0;
    }
    t->left = resolve_red_pair(t->left); 
    t->right = resolve_red_pair(t->right);
  }
  else return t;
}

int main() {
  struct rb_node *t = get_rbtree();
  t = resolve_red_pair(t);
  print_rbtree(t);
  return 0;
}
