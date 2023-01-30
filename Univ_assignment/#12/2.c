#include<stdio.h>
#include<stdlib.h>
char buf[128]; /* 関数 get_avl で用いるグローバル変数 */

struct student { int id; char name[32]; int score; };
typedef struct student datatype; /* ← 格納するデータは構造体 student */
struct avl_node { datatype data; struct avl_node *left, *right; int height; };

struct avl_node* get_avl() {
  struct avl_node *t;
  /* ドットだけなら葉 (NULL) を返す */
  if(fgets(buf,sizeof(buf),stdin)==NULL || buf[0]=='.')
    return NULL;
  else {
    /* ドットでなければ節点を表す構造体のアドレス t を用意 */
    t = (struct avl_node*)malloc(sizeof(struct avl_node));
    /* 高さを t->height に、学籍番号、名前、得点を t->data に格納 */
    sscanf(buf,"[%d]%d,%[^,],%d",&t->height,&t->data.id,t->data.name,&t->data.score);
    /* 左の子を t->left に、右の子を t->right に格納 */
    t->left = get_avl();
    t->right = get_avl();
    /* t を返す */
    return t;
  }
}

int height(struct avl_node *t){
  if(t==NULL) return 0;
  else return t->height;
}

void put_height(struct avl_node *t){
  int l = height(t->left), r = height(t->right);
  if(l >= r){t->height = l+1;}
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
  /* 厳密にいえば入力は AVL 木とは限らないが、関数 get_avl で入力の木を作れる */
  struct avl_node *t = get_avl();
  t = balance(t);
  print_avl(t);
  return 0;
}
