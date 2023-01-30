#include<stdio.h>
#include<math.h>

int main ( void )
{
  const double h = 0.0001;
  const double k = 1.0;
  const double T = 1.0;
  const int N = ( int ) ( T / h );

  double x = 1.0;
  double v = 0.0;

  for ( int n = 0; n < N + 1; n++ ) {
    double t = h * n;

    printf ( "%f %f\n", t, x);
    double k1 = h * k * x;
    double k2 = h * k * v;
    v -= k2;
    x += k1;
  }
}
