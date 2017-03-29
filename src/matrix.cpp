
#include "mathclass.h"

namespace jhm {

#define DET2x2(a,b,c,d) ((a)*(d) - (b)*(c))

// Inquiry Function

matrix
matrix::transpose() const
{
    matrix c;

    c.p[0][0] = getValue(0,0);
    c.p[0][1] = getValue(1,0);
    c.p[0][2] = getValue(2,0);
    c.p[1][0] = getValue(0,1);
    c.p[1][1] = getValue(1,1);
    c.p[1][2] = getValue(2,1);
    c.p[2][0] = getValue(0,2);
    c.p[2][1] = getValue(1,2);
    c.p[2][2] = getValue(2,2);

    return c;
}

m_real
matrix::det() const
{
    return ( getValue(0,0)* DET2x2(getValue(1,1),getValue(1,2),
								   getValue(2,1),getValue(2,2))
    	   - getValue(1,0)* DET2x2(getValue(0,1),getValue(0,2),
								   getValue(2,1),getValue(2,2))
    	   + getValue(2,0)* DET2x2(getValue(0,1),getValue(0,2),
								   getValue(1,1),getValue(1,2)) );
}

matrix
matrix::inverse() const
{
    matrix c;
    m_real d = this->det();

    if ( d != 0.0 )
    {
		c.p[0][0] =  DET2x2( getValue(1,1), getValue(1,2),
							 getValue(2,1), getValue(2,2) ) / d;
		c.p[1][0] = -DET2x2( getValue(1,0), getValue(1,2),
							 getValue(2,0), getValue(2,2) ) / d;
		c.p[2][0] =  DET2x2( getValue(1,0), getValue(1,1),
							 getValue(2,0), getValue(2,1) ) / d;
		c.p[0][1] = -DET2x2( getValue(0,1), getValue(0,2),
							 getValue(2,1), getValue(2,2) ) / d;
		c.p[1][1] =  DET2x2( getValue(0,0), getValue(0,2),
							 getValue(2,0), getValue(2,2) ) / d;
		c.p[2][1] = -DET2x2( getValue(0,0), getValue(0,1),
							 getValue(2,0), getValue(2,1) ) / d;
		c.p[0][2] =  DET2x2( getValue(0,1), getValue(0,2),
							 getValue(1,1), getValue(1,2) ) / d;
		c.p[1][2] = -DET2x2( getValue(0,0), getValue(0,2),
							 getValue(1,0), getValue(1,2) ) / d;
		c.p[2][2] =  DET2x2( getValue(0,0), getValue(0,1),
							 getValue(1,0), getValue(1,1) ) / d;
	}

	return c;
}

matrix
inverse( matrix const& m )
{
    return m.inverse();
}


// generator

matrix scaling( m_real s )
{
    vector v1( s, 0.0, 0.0 );
    vector v2( 0.0, s, 0.0 );
    vector v3( 0.0, 0.0, s );
    return matrix( v1, v2, v3 );
}

matrix scaling( m_real sx, m_real sy, m_real sz )
{
    vector v1( sx, 0.0, 0.0 );
    vector v2( 0.0, sy, 0.0 );
    vector v3( 0.0, 0.0, sz );
    return matrix( v1, v2, v3 );
}

matrix rotation( m_real angle, vector const& axis )
{
    vector v = angle * normalize( axis );
    quater q = exp( v/2.0 );
    return Quater2Matrix( q );
}

matrix reflection( vector const& normal )
{
    return scaling( 1.0f - 2.0f*normal.x()*normal.x(),
                    1.0f - 2.0f*normal.y()*normal.y(),
                    1.0f - 2.0f*normal.z()*normal.z() );
}

matrix mexp( vector const& v )
{
	m_real t = v.length();
	vector u = normalize( v );

	m_real x = u.x();
	m_real y = u.y();
	m_real z = u.z();
	m_real s = sin(t);
	m_real c = cos(t);
	m_real k = 1-c;

	vector v1( x*x*k + c, x*y*k - z*s, x*z*k + y*s );
	vector v2( x*y*k + z*s, y*y*k + c, y*z*k - x*s );
	vector v3( x*z*k - y*s, y*z*k + x*s, z*z*k + c );

	return matrix( v1, v2, v3 );
}

vector mlog( matrix const& m )
{
	m_real trace = m.getValue(0,0) + m.getValue(1,1) + m.getValue(2,2);
	m_real range = (trace-1.0f) / 2.0f;
	m_real div = 2.0f * sqrt(1.0f - range*range);
	if ( range> 1.0f ) range =  1.0f;
	if ( range<-1.0f ) range = -1.0f;
	m_real angle = ACOS( range );

	return vector( m.getValue(2,1)-m.getValue(1,2),
				   m.getValue(0,2)-m.getValue(2,0),
				   m.getValue(1,0)-m.getValue(0,1) ) * angle / div;
}

std::ostream& operator<<( std::ostream& os, matrix const& a )
{
	os<<"( "<<a.getValue(0,0)<<" , "<<a.getValue(0,1)<<" , "<<a.getValue(0,2)<<" )"<<std::endl;
	os<<"( "<<a.getValue(1,0)<<" , "<<a.getValue(1,1)<<" , "<<a.getValue(1,2)<<" )"<<std::endl;
	os<<"( "<<a.getValue(2,0)<<" , "<<a.getValue(2,1)<<" , "<<a.getValue(2,2)<<" )"<<std::endl;
    return os;
}

std::istream& operator>>( std::istream& is, matrix& a )
{
	static char	buf[256];
    //is >> "(" >> a[0] >> "," >> a[1] >> "," >> a[2] >> ")";
	is >> buf >> a[0] >> buf >> a[1] >> buf >> a[2] >> buf;
    return is;
}

matrix
interpolate( m_real t, matrix const& a, matrix const& b )
{
    quater q1 = Matrix2Quater( a );
    quater q2 = Matrix2Quater( b );

    if ( q1%q2 < 0 ) q2 = -q2;
    quater q = slerp( q1, q2, t );

    return Quater2Matrix( q );
}

vector
Matrix2EulerAngle( const matrix& m )
{
    m_real siny = -m.getValue(0,2);
    m_real cosy = sqrt( 1.0f - siny*siny );

	m_real sinx;
	m_real cosx;

	m_real sinz;
	m_real cosz;

	if ( cosy>EPS_jhm )
	{
	    sinx = m.getValue(1,2) / cosy;
		cosx = m.getValue(2,2) / cosy;

		sinz = m.getValue(0,1) / cosy;
		cosz = m.getValue(0,0) / cosy;
	}
	else
	{
	    sinx = - m.getValue(2,1);
		cosx =   m.getValue(1,1);

		sinz = 0.0;
		cosz = 1.0;
	}

	m_real x = atan2( sinx, cosx );
	m_real y = atan2( siny, cosy );
	m_real z = atan2( sinz, cosz );

    return vector(x,y,z);
}

matrix
EulerAngle2Matrix( const vector& v )
{
    matrix m = rotation( v.x(), x_axis ) *
               rotation( v.y(), y_axis ) *
               rotation( v.z(), z_axis );

    return m;
}

}

