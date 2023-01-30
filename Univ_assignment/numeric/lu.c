#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N ( 3 )
#define Eps ( 1e-8 )

void printMatrix ( const int n, double M [ n ] [ n ] )
{
  for ( int i = 0; i < n; i++ ) {
    for ( int j = 0; j < n; j++ ) {
      printf ( "%c%2.2f%s", ( M [ i ] [ j ] < 0 ) ? '-' : ' ', fabs ( M [ i ] [ j ] ), ( j == n - 1 ) ? "\n" : " " );
    }
  }
  printf ( "--\n" );
}
void printVector ( const int n, double v [ n ] )
{
  for ( int i = 0; i < n; i++ ) {
    printf ( "%c%2.2f\n", ( v [ i ] < 0 ) ? '-' : ' ', fabs ( v [ i ] ) );
  }
  printf ( "--\n" );
}

void checkLU (const int n, double A [ n ] [ n ],
	      double L [ n ] [ n ], double U [ n ] [ n ] )
{
  // Print L
  printf ( "L:\n" );
  printMatrix ( n, L );
  // Print U
  printf ( "U:\n" );
  printMatrix ( n, U );
  // Check LU = A
  int correct = 1;
  for ( int i = 0; i < n; i++ ) {
    for ( int j = 0; j < n; j++ ) {
      double r = 0.0;
      for ( int k = 0; k < n; k++ ) {
	r += L [ i ] [ k ] * U [ k ] [ j ];
      }
      if ( fabs ( r - A [ i ] [ j ] ) > Eps ) { correct = 0; }
    }
  }
  printf ( "%s: %s\n", __func__, correct ? "Good" : "Bad" );
}

void checkAnswer ( const int n, double A [ n ] [ n ], double x [ n ], double b [ n ] )
{
  // Check Ax = b
  int correct = 1;
  for ( int i = 0; i < n; i++ ) {
    double r = 0.0;
    for ( int j = 0; j < n; j++ ) {
      r += A [ i ] [ j ] * x [ j ];
    }
    if ( fabs ( r - b [ i ] ) > Eps ) { correct = 0; }
  }
  printf ( "%s: %s\n", __func__, correct ? "Good" : "Bad" );
}

void LUDecomposition ( const int n, double A [ n ] [ n ],
		       double L [ n ] [ n ], double U [ n ] [ n ], double r [ n ] )
{
  // Copy A to tmp to preserve A
  double tmp [ n ] [ n ];
  for ( int i = 0; i < n; i++ ) {
    for ( int j = 0; j < n; j++ ) {
      tmp [ i ] [ j ] = A [ i ] [ j ];
    }
  }

  // Prepare r for pivoting
  for ( int i = 0; i < n; i++ ) {
    r [ i ] = i;
  }

  //
  // Write the code for LU decomposition here
  //

}

void forwardSubstitution ( const int n, double L [ n ] [ n ],
			   double y [ n ], double b [ n ], double r [ n ] )
{
  for ( int i = 0; i < n; i++ ) {
    double r = b [ i ];
    for ( int j = 0; j < i; j++ ) {
      r -= L [ i ] [ j ] * y [ j ];
    }
    y [ i ] = r;
  }
}

void backwardSubstitution ( const int n, double U [ n ] [ n ],
			    double x [ n ], double y [ n ] )
{
  for ( int i = n - 1; i >= 0; i-- ) {
    double r = y [ i ];
    for ( int j = n - 1; j > i; j-- ) {
      r -= U [ i ] [ j ] * x [ j ];
    }
    x [ i ] = r / U [ i ] [ i ];
  }
}

int main ( void )
{
  double A [ N ] [ N ] = { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 1, 2 } };
  double b [ N ] = { 6, 9, 6 };
  double L [ N ] [ N ], U [ N ] [ N ];
  double x [ N ], y [ N ], r [ N ];

  LUDecomposition ( N, A, L, U, r );
  checkLU ( N, A, L, U );

  forwardSubstitution ( N, L, y, b, r );
  backwardSubstitution ( N, U, x, y );
  checkAnswer ( N, A, x, b );
}
