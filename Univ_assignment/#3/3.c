#include <stdio.h>

struct golden{
  long long int a;
  long long int b;
};

/* mult_golden: 第 1引数と第 2引数の積を返す関数 */
struct golden mult_golden(struct golden x, struct golden y) {
  struct golden z;
  z.a = x.a * y.a + x.b * y.b;
  z.b = x.a * y.b + y.a * x.b + x.b * y.b;
  return z;
}

/* 以下はコメント以外は変更しないこと */
int main() {
  struct golden x, y;
  scanf("%lld %lld", &x.a, &x.b);
  scanf("%lld %lld", &y.a, &y.b);
  x = mult_golden(x, y);
  printf("%lld %lld\n", x.a, x.b);
  return 0;
}
