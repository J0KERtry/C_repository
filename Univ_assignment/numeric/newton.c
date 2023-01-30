#include <stdio.h>
#include <math.h>

#define Epsilon ( 1e-14 )

double f ( double x ) { return x*x - 3*x + 2; } // solutions are n*PI (nは整数)
double dfdx ( double x ) { return 2*x - 3; }

double newton_method ( double ( *f ) ( double ), double ( *dfdx ) ( double ), double initial_value, double epsilon )
{
  double x = initial_value;

  int i = 0;
  while ( fabs ( f ( x ) ) > epsilon ) {
    fprintf ( stderr, "%d %1.16f\n", i, x );
    x = x - f ( x ) / dfdx ( x );
    i++;
  }

  return x;
}

int main ( void )
{
  double x = newton_method ( f, dfdx, 1.1, Epsilon ); // find x = 6.0 while starting at 7.0

  printf ( "answer = %1.16f\n", x );
}
