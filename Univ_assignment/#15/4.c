#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define ROSENZU "rosenzu.txt" /* 路線図データファイル */
#define SETMAX 10600 /* 集合の要素数の最大値 (駅の数) */
char buf[256]; /* 入力された文字列を格納するグローバル変数 */
int dist[SETMAX]; /* 指定された駅から各駅までの最短距離を格納するグローバル変数 */

struct node { int eki, rosen, kyori; struct node *next; };
struct set { int elements[SETMAX]; int size; };

void init_set(struct set *p, int n, int e) {
  int i, j = 0;
  p->size = n-1;

  for(i=0; i<=p->size; i++){
    if(i!=e){
      p->elements[j] = i;
      j++;
    }
  }
}

int delete_min(struct set *p) {
  int i, min, min_num, store;
  if(p->size==0)return -1;
  else{
    min = dist[p->elements[0]]; 
    min_num = 0;
    for(i=1; i<p->size; i++){
      if(min > dist[p->elements[i]]){
	min = dist[p->elements[i]]; 
	min_num = i;
      }
    }
  }
  store = p->elements[min_num];
  p->elements[min_num] = p->elements[p->size-1];
  p->size--;
  return store;
}

void add_edge(struct node *adjlist[], int eki1, int eki2, int rosen, int kyori) {
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

int dijkstra(struct node *adjlist[], int eki1, int eki2, int ekisu) {
  int i, cur;
  struct set unknown;
  // eki1 -> eki1 の最短距離は 0 、それ以外は最大の整数値
  while(i!=SETMAX){dist[i]=INT_MAX; i++;}
  dist[eki1] = 0;

  // 最短距離を格納する変数 cur に eki1 を入れ、最短距離が確定していない駅の集合 unknown
  cur = eki1;
  init_set(&unknown, ekisu, eki1);

  // unknown が空になるか cur が eki2 と等しくなるまで
  while(unknown.size!=0 && cur!=eki2){
    // 駅 cur に隣接するすべての駅について実行
    while(adjlist[cur]!=NULL){
      int adj = adjlist[cur]->eki;    // adj <- 隣接する駅の番号
      int d = adjlist[cur]->kyori;    // d <- 隣接する駅までの距離
      if(dist[adj] > (dist[cur] + d)) dist[adj] = (dist[cur] + d);
      adjlist[cur] = adjlist[cur]->next;
    }
    cur = delete_min(&unknown);
  }

  return dist[eki2];
}

int main() {
  int eki1, eki2, rosen, ekisu, i, kyori;
  FILE *fp = fopen(ROSENZU,"r"); /* 路線図ファイルを読む準備 */
  fscanf(fp, "%d ", &ekisu); /* 1行目の駅数を読取り */
  struct node *adjlist[ekisu];
  /* 隣接リスト表現を初期化。すべての頂点に対する隣接リストを空にする */
  for(i=0;i<ekisu;++i) adjlist[i] = NULL;
  while(fgets(buf,sizeof(buf),fp)!=NULL) {
    /* 隣り合う駅の情報を読取り */
    sscanf(buf, "%d:%d:%d:%d ", &eki1, &eki2, &rosen, &kyori);
    /* そのデータを隣接リスト表現のグラフに追加 */
    add_edge(adjlist, eki1, eki2, rosen, kyori);
  }
  fclose(fp);
  scanf("%d %d ", &eki1, &eki2);
  printf("%d\n", dijkstra(adjlist, eki1, eki2, ekisu));
  /*for(i=0;i<ekisu;++i)
    if(dist[i] < INT_MAX)
    printf("%d: %d\n", i, dist[i]);*/
  return 0;
}
