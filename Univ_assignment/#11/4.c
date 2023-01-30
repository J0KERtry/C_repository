#include<stdio.h>
#include<stdlib.h>
char buf[128]; /* 関数 get_tree で用いるグローバル変数 */

struct student { int id; char name[32]; int score; };
typedef struct student datatype; /* ← 格納するデータは構造体 student */
struct node { datatype data; struct node *left, *right; };

/* 葉を含む行きがけ順で表現された文字列を二分木に変換 */
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

void find_info(struct node *t, int id) {
  if(t==NULL){printf("Not found.");}
  else if(id < t->data.id){find_info(t->left, id);}
  else if(id > t->data.id){find_info(t->right, id);}
  else{printf("%s,%d", t->data.name, t->data.score);}
}

int main() {
  int id;
  struct node *t = get_tree();
  scanf("%d␣", &id);
  find_info(t,id);
  return 0;
}
