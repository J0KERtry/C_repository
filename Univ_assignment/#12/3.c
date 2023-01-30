#include<stdio.h>
#include<stdlib.h>
char buf[128];

struct student { int id; char name[32]; int score; };
typedef struct student datatype; /* ← 格納するデータは構造体 student */
struct avl_node { datatype data; struct avl_node *left, *right; int height; };

int height(struct avl_node *t){
  if(t==NULL) return 0;
  else return t->height;
}

void put_height(struct avl_node *t){
  int l = height(t->left), r = height(t->right);
  if(l==0 && r==0) t->height = 1;
  else if(l >= r){t->height = l+1;}
  else{t->height = r+1;}
}

struct avl_node* rotate_right(struct avl_node *t) {
  struct avl_node *pivot = t->left;
  if( pivot!=NULL ){
    // ポインタの付け替え
    t->left = pivot->right;
    pivot->right = t;

    // 高さの更新
    put_height(t);
    put_height(pivot);
    return pivot;
  }
  else return t;
}

struct avl_node* rotate_left(struct avl_node *t) {
  struct avl_node *pivot = t->right;
  if( pivot!=NULL){
    // ポインタの付け替え
    t->right = pivot->left;
    pivot->left = t;

    // 高さの更新
    put_height(t);
    put_height(pivot);
    return pivot;
  }
  else return t;
}

struct avl_node* balance(struct avl_node *t) {
  // 高さの差の絶対値が 1 以下のとき
  if( abs( height(t->left)-height(t->right) ) <= 1 ) return t;

  //  高さの差が2のとき
  else{   

    // 左の部分木のほうが 2 高いとき
    if(height(t->left) - height(t->right) == 2){    
      // 左の部分木の左が高いとき
      if(height(t->left->left) >= height(t->left->right)){
	rotate_right(t);
      }
      // 左の部分木の右が高いとき
      else{
	t->left = rotate_left(t->left);
	rotate_right(t);
      }
    }

    // 右の部分木のほうが 2 高いとき
    else{   
      // 右の部分木の左が高いとき
      if(height(t->right->left) >= height(t->right->right)){
	t->right = rotate_right(t->right);
	rotate_left(t);
      }
      // 右の部分木の右が高いとき
      else{
	rotate_left(t);
      }
    }
  }
}

struct avl_node* avl_insert(struct avl_node *t, struct student d) {
  // 節点が葉(NULL)のとき
  if(t == NULL){
    t = (struct avl_node*)malloc(sizeof(struct avl_node));
    t->data = d;
    t->left = NULL; t->right = NULL;
    t->height = 1;
  }
  // 節点が葉でないとき
  else{
    if(t->data.id > d.id){ t->left = avl_insert(t->left, d); }
    else{ t->right = avl_insert(t->right, d); } 
  }
  put_height(t);
  balance(t);
}

void print_avl(struct avl_node *t) {
  if(t==NULL)
    printf(".\n");
  else {
    printf("[%d]%d,%s,%d\n",t->height,t->data.id,t->data.name,t->data.score);
    print_avl(t->left);
    print_avl(t->right);
  }
}

int main() {
  struct avl_node *t = NULL;
  struct student st;
  while(fgets(buf,sizeof(buf),stdin)!=NULL) {
    /* 学生の情報を読取り */
    sscanf(buf,"%d,%[^,],%d",&st.id,st.name,&st.score);
    /* AVL 木にそのデータを追加 */
    t = avl_insert(t, st);
  }
  print_avl(t);
  return 0;
}
