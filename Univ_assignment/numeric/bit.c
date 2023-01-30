#include <stdio.h>
#include <string.h>

#define DOUBLE_BITS ( 64 )

// Get the i-th bit of a double variable x
// The highest bit (i.e., the sign) is 63
int bit ( const double x, const int i )
{
  unsigned long v;
  memcpy ( &v, &x, sizeof ( double ) );
  return  ( v >> i ) & 1;
}

int main ( void )
{
  double x = 0.1;

  for ( int i = DOUBLE_BITS - 1; i >= 0; i-- ) {
    int b = bit ( x, i );
    // Print the i-th bit while inserting spaces
    // to separate the sign, mantissa, and exponent
    printf ( "%d%s", b, ( i == 63 || i == 52 ) ? " " : "" );
  }
  printf ( "\n" );
}
