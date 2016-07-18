#include <stdio.h>
#include <math.h>
#include <assert.h>

const int SQEQ_INF = -1;
const int ERROR = 404;
const double e = 0.0000000001;

//! Search discriminant quadratic equation
//! @param a is the coefficient of x^2
//! @param b is the coefficient of x
//! @param c is free coefficient
//! @return discriminant
double SearhDst ( double a, double b, double c )
{
    return b*b - 4*a*c;
}

//! Comparison with zero using precision equal to e ( line 7 )
//! @param a comparing numbers
//! @return true, if a is zero, or false,if a not zero
bool IsZero ( double a )
{
    return ( fabs( a ) < e );

}

//! Сomparing numbers with a precision equal to e ( line 7 )
//! @param a is first comparing numbers
//! @param b is second comparing numbers
//! @return true, if a equals b, or false,if a not equals b
bool IsEql ( double a, double b )
{
    return ( fabs( a - b ) < e );
}

//! Search for root of quadratic equation 
//! @param a is the coefficient of x^2
//! @param b is the coefficient of x
//! @param c is free coefficient
//! @param x are roots of array
//! @return number of roots or SQEQ_INF, if infinitely many roots
int SqEquation ( double a, double b, double c, double* x )
{

    assert( x );

    if ( IsZero( a ) && IsZero( b ) && !IsZero( c ) ) //с=0,conflicts with c<>0
        return ERROR;

    if ( IsZero( a ) && IsZero( b ) && IsZero( c ) )
        return SQEQ_INF;

    if ( !IsZero( a ) )
    {
        double d = 0;
        d = SearhDst( a, b, c );

        if ( d > 0 )
        {
            x[0] = ( -b - sqrt( d ) )/( 2*a );
            x[1] = ( -b + sqrt( d ) )/( 2*a );
            return 2;
        }

        if ( d == 0 )
        {
            x[0] = -b/2/a;
            return 1;
        }

        if ( d < 0 )
            return 0;
    }
    else
    {
        x[0] = -c/b;
        return 1;
    }

    return 0;
}

//! Finding the roots of a function check
void SqEquationTest()
{
    double* x = ( double* )( malloc( 2*sizeof( double ) ) );

    assert ( SqEquation( 0, 0, 0, x ) == SQEQ_INF );
    assert ( SqEquation( 0, 0, 1, x ) == ERROR );
    assert ( SqEquation( 1, 1, 1, x ) == 0 );
    assert ( SqEquation( 1, 2, 1, x ) == 1 && IsEql( x[0], -1 ) );
    assert ( SqEquation( 1, -5, 6, x ) == 2 && IsEql( x[0], 2 ) && IsEql ( x[1], 3 ) );
    assert ( SqEquation( 0, 1, 1, x ) == 1 && IsEql( x[0], -1 ) );
    assert ( SqEquation( 0, 1, 0, x ) == 1 && IsEql( x[0], 0 ) );
    assert ( SqEquation( 1, 0, 0, x ) == 1 && IsEql( x[0], 0 ) );
    assert ( SqEquation( 1, 1, 0, x ) == 2 && IsEql( x[0], -1 ) && IsEql( x[1], 0 ) );
    //assert ( SqEquation( 0, 0, 1, 0 ) );//becose

    printf( "Completed!!!!" );
}

int main()
{
    /*double a = 0, b = 0, c = 0;
    scanf ( "%lg %lg %lg", &a, &b, &c );
    double* x = ( double* )( malloc( 2*sizeof( double ) ) );

    int chE = SqEquation( a, b, c, x );

    printf ( "Solutions:\n" );
    if ( chE == ERROR )
        printf( "The roots of the equation does not exist\n" );
    if ( chE == SQEQ_INF )
        printf( "INF < x < INF\n" );
    if ( chE > 0 )
        for( int i = 0; i < chE ; i++ )
            printf ( "%lg ", x[i] );*/

    SqEquationTest();

    return 0;
}
