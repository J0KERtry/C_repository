#include<stdio.h>
#include<stdlib.h>
char buf[128]; /* 関数 get_tree で用いるグローバル変数 */

struct student { int id; char name[32]; int score; };
typedef struct student datatype; /* ← 格納するデータは構造体 student */
struct node { datatype data; struct node *left, *right; };

struct node* get_tree() {
  struct node *t;
  if(fgets(buf,sizeof(buf),stdin)==NULL || buf[0]=='.')
    return NULL;
  else {
    t = (struct node*)malloc(sizeof(struct node));
    sscanf(buf,"%d,%[^,],%d",&t->data.id,t->data.name,&t->data.score);
    t->left = get_tree();
    t->right = get_tree();
    return t;
  }
}

struct node* bst_insert(struct node *t, struct student d) {
  if(t == NULL){
    t = (struct node*)malloc(sizeof(struct node));
    t->data = d;
    t->left = NULL;
    t->right = NULL;
  }else if(d.id < t->data.id){
    if(t->left==NULL){ 
      t->left = (struct node*)malloc(sizeof(struct node));
      t->left->data = d; 
      t->left->left = NULL;
      t->left->right = NULL;
    }
    else{ bst_insert(t->left, d); }

  }else if(d.id > t->data.id){
    if(t->right==NULL){ 
      t->right = (struct node*)malloc(sizeof(struct node));
      t->right->data = d; 
      t->right->left = NULL;
      t->right->right = NULL;
    }
    else{ bst_insert(t->right, d); }
  }
  return t;
}

void print_bst(struct node *t) {
  if(t==NULL){printf(".\n");}
  else{
    printf("%d,%s,%d\n", t->data.id, t->data.name, t->data.score);
    print_bst(t->left);
    print_bst(t->right);
  }
}

int main() {
  struct student d;
  struct node *t = get_tree();
  scanf("%d,%[^,],%d ", &d.id, d.name, &d.score);
  t = bst_insert(t, d);
  print_bst(t);
  return 0;
}
