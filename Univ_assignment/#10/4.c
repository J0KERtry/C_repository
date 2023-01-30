#include<stdio.h>
#include<stdlib.h>
#define SIZE 101
struct student { int id; char name[32]; int score; };
struct node { struct student data; struct node *next; };

int hash(char *s) {
  int result = (int)*s % SIZE;
  s++;
  for(; *s!='\0'; s++){
    result = (result*128 + (int)*s) % SIZE;
  }
  return result;
}

void set_data(struct node *table[], struct student st) {
  int num = hash(st.name);
  printf("%d\n", num);

  if(table[num]==NULL){
    table[num]->data = st;
    table[num]->next = NULL;
  }else{
    struct node *new;
    new->data = st;
    new->next = table[num];
    table[num] = new;
  }
}

int main() {
  int i;
  char buf[128];
  struct student st;
  struct node *table[SIZE], *p;
  /* ハッシュ表の配列の各要素を NULL で初期化 */
  for(i=0;i<SIZE;++i) table[i] = NULL;
  while(fgets(buf,sizeof(buf),stdin)!=NULL) {
    sscanf(buf, "%d,%[^,],%d", &st.id, st.name, &st.score);
    set_data(table, st); /* ハッシュ表に st を登録 */
  }
  for(i=0;i<SIZE;++i) {
    p = table[i];
    while(p!=NULL) {
      st = p->data;
      printf("(%d)%d,%s,%d\n", i, st.id, st.name, st.score);
      p = p->next;
    }
  }
  return 0;
}
