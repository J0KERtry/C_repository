#include<stdio.h>
#include<stdlib.h>
char buf[256];
struct node { int eki, rosen; float kyori; struct node *next; };

void add_edge(struct node *adjlist[], int eki1, int eki2, int rosen, float kyori) {
  struct node *t1, *t2;
  t1 = (struct node*)malloc(sizeof(struct node));
  t2 = (struct node*)malloc(sizeof(struct node));
  // eki1 の情報を eki2 に追加
  t1->eki = eki1; t1->rosen = rosen; t1->kyori = kyori; 
  t1->next = adjlist[eki2];
  adjlist[eki2] = t1;
  // eki2 の情報を eki1 に追加
  t2->eki = eki2; t2->rosen = rosen; t2->kyori = kyori; 
  t2->next = adjlist[eki1];
  adjlist[eki1] = t2;
}

float two_hop_kyori(struct node *adjlist[], int eki) {
  int i;
  float max;
  float route[128] = {0}; // eki から 要素番号+1駅 の最大距離を格納

  struct node *p = adjlist[eki];
  struct node *alt;
  while(p!=NULL){
    // 1駅離れている距離を格納
    route[p->eki] = p->kyori;

    // 1駅離れたところから、もう1駅の最大距離を求める
    max = 0.000;
    alt = adjlist[p->eki];
    while(alt!=NULL){
      // 距離が最大で、自身に戻っていない場合 max を更新
      if((alt->kyori > max) && (alt->eki!=eki)){ max = alt->kyori;} 
      alt = alt->next;
    } 
    route[p->eki] += max;
    p = p->next;
  }

  max = 0.000;
  for(i=0; i<128; i++){
    if(route[i]>max)max=route[i];
  }
  return max;
}

int main() {
  int eki1, eki2, rosen, ekisu, i;
  float kyori;
  scanf("%d ", &ekisu);
  struct node *adjlist[ekisu];
  /* 隣接リスト表現を初期化。すべての頂点に対する隣接リストを空にする */
  for(i=0;i<ekisu;++i) adjlist[i] = NULL;
  while(fgets(buf,sizeof(buf),stdin)!=NULL) {
    /* 隣り合う駅の情報を読取り */
    sscanf(buf, "%d:%d:%d:%f ", &eki1, &eki2, &rosen, &kyori);
    /* そのデータを隣接リスト表現のグラフに追加 */
    add_edge(adjlist, eki1, eki2, rosen, kyori);
  }
  for(i=0;i<ekisu;++i)
    printf("%d: %.3f\n", i, two_hop_kyori(adjlist, i));
    
  return 0;
}
