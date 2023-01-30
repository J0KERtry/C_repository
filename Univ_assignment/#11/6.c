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

void print_bst(struct node *t) {
  if(t==NULL){printf(".\n");}
  else{
    printf("%d,%s,%d\n", t->data.id, t->data.name, t->data.score);
    print_bst(t->left);
    print_bst(t->right);
  }
}

struct node* bst_delete(struct node *t, int id) {
  struct node *child;
  if(t==NULL)return NULL;
  if(t->data.id > id){
    t->left = bst_delete(t->left, id);
  }else if(t->data.id < id){
    t->right = bst_delete(t->right, id);
  }else{
    if(t->left == NULL && t->right == NULL){
      free(t);
      return NULL;
    }else if(t->left == NULL){      //右のみ存在
      child = t->right;
      t->data = child->data;
      t->left = child->left;
      t->right = child->right;
      free(child);
      return t;
    }else if(t->right == NULL){      //左のみ存在
      child = t->left;
      t->data = child->data;
      t->left = child->left;
      t->right = child->right;
      free(child); 
      return t;
    }else{     //左右の子あり
      child = t->left;
      struct node *child_prev = t;
      while(child->right != NULL){//左の子の最大値を探索
	child_prev = child;
	child = child->right;
      }
      t->data = child->data;
      if(child->left != NULL){
	if(child_prev != t){
	  child_prev->right = child->left;
	}
      }
      free(child);        //子ノードを削除
      return t;
    }
  }
}

int main() {
  int id;
  struct node *t = get_tree();
  scanf("%d ", &id);
  t = bst_delete(t, id);
  print_bst(t);
  return 0;
}
