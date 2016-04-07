
#include "mathclass.h"

namespace jhm {

matrix operator*( m_real a, matrix const& b )
{
    matrix c;

	for( int i=0; i<3; i++ )
	for( int j=0; j<3; j++ )
		c.p[i][j] = a * b.getValue(i,j);

    return c;
}

matrix operator*( matrix const& b, m_real a )
{
    matrix c;

	for( int i=0; i<3; i++ )
	for( int j=0; j<3; j++ )
		c.p[i][j] = a * b.getValue(i,j);

    return c;
}

matrix operator+( matrix const& a, matrix const& b )
{
    matrix c;

	for( int i=0; i<3; i++ )
	for( int j=0; j<3; j++ )
		c.p[i][j] = a.getValue(i,j) + b.getValue(i,j);

    return c;
}

matrix& operator+=( matrix& a, matrix const& b )
{
	for( int i=0; i<3; i++ )
	for( int j=0; j<3; j++ )
		a.p[i][j] += b.getValue(i,j);

    return a;
}

matrix operator-( matrix const& a, matrix const& b )
{
    matrix c;

	for( int i=0; i<3; i++ )
	for( int j=0; j<3; j++ )
		c.p[i][j] = a.getValue(i,j) - b.getValue(i,j);

    return c;
}

matrix& operator-=( matrix& a, matrix const& b )
{
	for( int i=0; i<3; i++ )
	for( int j=0; j<3; j++ )
		a.p[i][j] -= b.getValue(i,j);

    return a;
}

position operator*( matrix const& b, position const& a )
{
    position c;

	c.p[0] =  b.getValue(0,0)*a.getValue(0)
			+ b.getValue(0,1)*a.getValue(1)
			+ b.getValue(0,2)*a.getValue(2);

	c.p[1] =  b.getValue(1,0)*a.getValue(0)
			+ b.getValue(1,1)*a.getValue(1)
			+ b.getValue(1,2)*a.getValue(2);


	c.p[2] =  b.getValue(2,0)*a.getValue(0)
			+ b.getValue(2,1)*a.getValue(1)
			+ b.getValue(2,2)*a.getValue(2);

    return c;
}

position operator*( position const& a, matrix const& b )
{
    position c;

	c.p[0] =  b.getValue(0,0)*a.getValue(0)
			+ b.getValue(1,0)*a.getValue(1)
			+ b.getValue(2,0)*a.getValue(2);

	c.p[1] =  b.getValue(0,1)*a.getValue(0)
			+ b.getValue(1,1)*a.getValue(1)
			+ b.getValue(2,1)*a.getValue(2);


	c.p[2] =  b.getValue(0,2)*a.getValue(0)
			+ b.getValue(1,2)*a.getValue(1)
			+ b.getValue(2,2)*a.getValue(2);
    
    return c;
}

position& operator*=( position& a, transf const& b )
{
    a = a * b.m + b.v;
    return a;
}

position operator*( position const& a, transf const& b )
{
    return ( a * b.m + b.v );
}

vector operator*( matrix const& b, vector const& a )
{
    vector c;


	c.p[0] =  b.getValue(0,0)*a.getValue(0)
			+ b.getValue(0,1)*a.getValue(1)
			+ b.getValue(0,2)*a.getValue(2);

	c.p[1] =  b.getValue(1,0)*a.getValue(0)
			+ b.getValue(1,1)*a.getValue(1)
			+ b.getValue(1,2)*a.getValue(2);


	c.p[2] =  b.getValue(2,0)*a.getValue(0)
			+ b.getValue(2,1)*a.getValue(1)
			+ b.getValue(2,2)*a.getValue(2);

    return c;
}

vector operator*( vector const& a, matrix const& b )
{
    vector c;

	c.p[0] =  b.getValue(0,0)*a.getValue(0)
			+ b.getValue(1,0)*a.getValue(1)
			+ b.getValue(2,0)*a.getValue(2);

	c.p[1] =  b.getValue(0,1)*a.getValue(0)
			+ b.getValue(1,1)*a.getValue(1)
			+ b.getValue(2,1)*a.getValue(2);


	c.p[2] =  b.getValue(0,2)*a.getValue(0)
			+ b.getValue(1,2)*a.getValue(1)
			+ b.getValue(2,2)*a.getValue(2);

    return c;
}

unit_vector& operator*=( unit_vector& a, matrix const& b )
{
	a = normalize( ((vector)a) * b );

    return a;
}

unit_vector operator*( unit_vector const& a, matrix const& b )
{
    return normalize( ((vector)a) * b );
}

unit_vector& operator*=( unit_vector& a, transf const& b )
{
    a = a * b.m;
    return a;
}

unit_vector operator*( unit_vector const& a, transf const& b )
{
    return ( a * b.m );
}

vector& operator*=( vector& a, transf const& b )
{
    a = a * b.m;
    return a;
}

vector operator*( vector const& a, transf const& b )
{
    return ( a * b.m );
}

matrix operator*( matrix const& a, matrix const& b )
{

	vector v1(    a.getValue(0,0)*b.getValue(0,0)
				+ a.getValue(0,1)*b.getValue(1,0)
				+ a.getValue(0,2)*b.getValue(2,0),
				  a.getValue(0,0)*b.getValue(0,1)
				+ a.getValue(0,1)*b.getValue(1,1)
				+ a.getValue(0,2)*b.getValue(2,1),
				  a.getValue(0,0)*b.getValue(0,2)
				+ a.getValue(0,1)*b.getValue(1,2)
				+ a.getValue(0,2)*b.getValue(2,2) );

	vector v2(    a.getValue(1,0)*b.getValue(0,0)
				+ a.getValue(1,1)*b.getValue(1,0)
				+ a.getValue(1,2)*b.getValue(2,0),
				  a.getValue(1,0)*b.getValue(0,1)
				+ a.getValue(1,1)*b.getValue(1,1)
				+ a.getValue(1,2)*b.getValue(2,1),
				  a.getValue(1,0)*b.getValue(0,2)
				+ a.getValue(1,1)*b.getValue(1,2)
				+ a.getValue(1,2)*b.getValue(2,2) );

	vector v3(    a.getValue(2,0)*b.getValue(0,0)
				+ a.getValue(2,1)*b.getValue(1,0)
				+ a.getValue(2,2)*b.getValue(2,0),
				  a.getValue(2,0)*b.getValue(0,1)
				+ a.getValue(2,1)*b.getValue(1,1)
				+ a.getValue(2,2)*b.getValue(2,1),
				  a.getValue(2,0)*b.getValue(0,2)
				+ a.getValue(2,1)*b.getValue(1,2)
				+ a.getValue(2,2)*b.getValue(2,2) );

    return matrix( v1, v2, v3 );
}

transf operator*( transf const& a, transf const& b )
{
    return transf( a.m * b.m, a.v * b.m + b.v );
}

transf& operator*=( transf& a, transf const& b )
{
    a.m = a.m * b.m;
    a.v = a.v * b.m + b.v;

    return a;
}

}