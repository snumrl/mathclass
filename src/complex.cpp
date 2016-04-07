
#include "mathclass.h"

namespace jhm {

complex operator-(complex const& a)
{
    return complex( -a.p[0], -a.p[1]);
}

complex inverse(complex const& a)
{
    return complex( a.p[0], -a.p[1]);
}

complex operator+ (complex const& a, complex const& b)
{
    return	complex(a.p[0] + b.p[0], a.p[1] + b.p[1]);
}

complex operator- (complex const& a, complex const& b)
{
	return	complex(a.p[0] - b.p[0], a.p[1] - b.p[1]);
}

complex operator* (m_real a, complex const& b)
{
	return	complex (a * b.p[0], a * b.p[1]);
}

complex operator* (complex const& a, m_real b)
{
    return	complex(a.p[0] * b, a.p[1] * b);
}

complex operator/ (complex const& a, m_real b)
{
	return	complex(a.p[0] / b, a.p[1] / b);
}

m_real operator% (complex const& a, complex const& b)
{
	return	(a.p[0] * b.p[0] + a.p[1] * b.p[1]);
}

complex operator* (complex const& a, complex const& b)
{
    complex c;
    c.p[0] = a.p[0]*b.p[0] - a.p[1]*b.p[1];
    c.p[1] = a.p[0]*b.p[1] + a.p[1]*b.p[0];
    return c;
}

m_real len( complex const& v )
{
    return sqrt( v.p[0]*v.p[0] + v.p[1]*v.p[1] );
}

m_real
complex::length() const
{
    return sqrt( p[0]*p[0] + p[1]*p[1] );
}

complex
complex::normalize() const
{
	return (*this)/this->length();
}

std::ostream& operator<<( std::ostream& os, complex const& a )
{
    os << "( " << a.p[0] << " , " << a.p[1] << " )";
    return os;
}

std::istream& operator>>( std::istream& is, complex& a )
{
	static char	buf[256];
    //is >> "(" >> a.p[0] >> "," >> a.p[1] >> ")";
	is >> buf >> a.p[0] >> buf >> a.p[1] >> buf;
    return is;
}

complex c_exp(m_real theta)
{
	return complex(cos(theta), sin(theta));
}

m_real c_ln(complex const& c)
{
	return	atan2(c.p[1], c.p[0]);
}

complex
slerp( complex const& a, complex const& b, m_real t )
{
	m_real c = a % b;

	if ( 1.0+c > EPS_jhm )
	{
		if ( 1.0-c > EPS_jhm )
		{
			m_real theta = acos( c );
			m_real sinom = sin( theta );
			return ( a*sin((1.0f-t)*theta) + b*sin(t*theta) ) / sinom;
		}
		else
			return (a*(1.0f-t) + b*t).normalize();
	}
	else	return a*sin((0.5f-t)*M_PI) + b*sin(t*M_PI);
}

complex
interpolate( m_real t, complex const& a, complex const& b )
{
	return slerp( a, b, t );
}

m_real
distance( complex const& a, complex const& b )
{
	return MIN( fabs(c_ln( a.inverse()* b)), fabs(c_ln( a.inverse()*-b)) );
}

m_real
difference( complex const& a, complex const& b )
{
	return c_ln( b.inverse() * a );
}

}